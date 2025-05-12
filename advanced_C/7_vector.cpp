#include <algorithm>
#include <cstdint>

template<typename T>
class vector {
    T* arr_;
    size_t size_;
    size_t capacity_;

public:
    //----------------------------------------------------------------------
    //ITERATOR
    class iterator {
        T* ptr;
        explicit iterator(T* ptr) : ptr(ptr) {}

    public:
        iterator(const iterator&) = default;

        iterator& operator=(const iterator&) = default;

        T& operator*() const { return *ptr; }
        iterator& operator++() {
            ++ptr;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++ptr;
            return tmp;
        }
    };

    iterator begin() {
        return iterator{arr_};
    }

    iterator end() {
        return iterator{arr_ + size_};
    }

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
    return 0;
}
