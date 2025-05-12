#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

template<typename T>
class vector {
    T* arr_;
    size_t size_;
    size_t capacity_;

    //----------------------------------------------------------------------
    //ITERATOR
    //jeszcze warto dodac reverse and const reverse iterator
    //adapter for iterator, tylkoc wszystko reversed std::reverse<> pozwala to zrobic

    template<bool IsConst>
    //class const_iterator {} //nie mozna zmieniac to, co on zwraca
    //zeby nie robic copy_paste -> template
    class base_iterator {
    public:
        using pointer_type = std::conditional_t<IsConst, const T *, T *>;
        using reference_type = std::conditional_t<IsConst, const T &, T &>;
        using value_type = T;

    private:
        pointer_type ptr; //jezeli true -> const T*, else T*


    public:
        explicit base_iterator(T* ptr) : ptr(ptr) {}

        base_iterator(const base_iterator&) = default;

        base_iterator& operator=(const base_iterator&) = default;

        reference_type operator*() const { return *ptr; }
        pointer_type operator->() const { return ptr; }

        base_iterator& operator++() {
            ++ptr;
            return *this;
        }

        base_iterator operator++(int) {
            base_iterator tmp = *this;
            ++ptr;
            return tmp;
        }
    };

public:
    using iterator = base_iterator<false>;
    using const_iterator = base_iterator<true>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin() { return {arr_}; }

    iterator end() { return {arr_ + size_}; }

    const_iterator begin() const { return {arr_}; }

    const_iterator end() const { return {arr_ + size_}; }

    const_iterator cbegin() const { return arr_; }

    const_iterator cend() const { return arr_ + size_; }

    //--------------------------------------------------------------------------------------
    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }
        T* new_arr = reinterpret_cast<T *>(new char[new_capacity * sizeof(T)]);
        //new_arr = new T[new_capacity]; problem - nie trzeba wywoływac konstruktory klas złożonych
        //a jak nie ma konstruktora domyślnego u T?
        //allocatory działają akurat w taki sposob
        size_t index = 0;
        try {
            for (; index < size_; ++index) {
                //new_arr[i] = arr_[i]; UB, bo new_arr[i] - row bites, nie mozna, trzeba stworzyc T
                // instead: używamy placement-new, który:
                //  a) konstruuje **w miejscu** (w surowych bajtach) nowy obiekt T
                //  b) wywołuje konstruktor kopiujący T::T(const T&)
                new(new_arr + index) T(std::move(arr_[index])); //konstruktor T może rzucić wyjątek
                //stworz w new_arr + i przez wywołanie kosntruktora obiekt typu T
            }
        } catch (...) {
            //jak jakis T rzuci wyjątek, mamy usunąć to, co już przeniesliśmy
            for (size_t old_index = 0; old_index < index; ++old_index) {
                (new_arr + old_index)->~T();
            }
            delete[] reinterpret_cast<char *>(new_arr);
            throw;
        }

        //delete[] arr_; wywoła ilośc destruktorów == ilosci elemtów(charow) w arr_ , a alokujemy arr_ jako new char
        for (index = 0; index < size_; ++index) {
            (arr_ + index)->~T(); //wywołujemy dokładnie tyle destruktorów ile było obiektow
        }
        delete[] reinterpret_cast<char *>(arr_);

        arr_ = new_arr;
        capacity_ = new_capacity;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ > 0 ? capacity_ * 2 : 1);
            //push_back wygląta podobnie, tylko zprawdzic exception od obiekta, który chcemy dodac
        }
    }
};

//vector bool
template<>
class vector<bool> {
    char* arr_;
    size_t size_;
    size_t capacity_;

    struct BitReference {
        char* cell;
        uint8_t index;

        BitReference(char* cell, uint8_t index) : cell(cell), index(index) {}

        BitReference operator=(bool b) {
            if (b) {
                *cell |= (1 << index);
            } else {
                *cell &= ~(1 << index);
            }
            return *this;
        }

        operator bool() const {
            return *cell & (1 << index);
        }
    };

public:
    BitReference operator[](uint8_t index) {
        return BitReference(arr_ + index / 8, index % 8);
    }
};

int main() {

    std::vector<int> vec(10);
    std::vector<int>::iterator it = vec.begin() + 5;
    //nie mozna w taki sposob robic z referencjami oraz pointerami
    //jak się zachowuje iterator?
    //rownież UB

    //po swap iteratopr ma wskazywac na ten sam adres jak wskazywał przed
    vec.push_back(10);
    std::cout << *it;

    //dla deq ok z pointerami oraz referencjami, ale UB z iteratorem
    //dla list, map, set wszystko ok, wszystko jest valid
    return 0;
}
