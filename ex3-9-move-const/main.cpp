#include <iostream>

class Array {
    int *data{nullptr};
    int size{0};
    int capacity{0};

public:
    Array(int _size = 0): size{0}, capacity{_size} {
        std::cout << "default constructor" << std::endl;
        data = new int[capacity];
    }

    Array(const Array &other): size(other.size), capacity(other.capacity) {
        std::cout << "copy constructor" << std::endl;
        if (&other == nullptr)
            return;
        data = new int[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    Array(Array&& other) noexcept : size(other.size), capacity(other.capacity) { //noexcept - brak żadnych exceptions
        std::cout << "move constructor" << std::endl;
        data = other.data;
        other.data = nullptr; // trzeba żeby data i other.data nie wskazywały na to samo miejsce w pamieci
        //już się nie tworzy kopia other, tylko przekazujemy adres data.other do data
    }

    ~Array() {
        std::cout << "destructor" << std::endl;
        delete[] data;
    }

    Array& operator=(const Array &other) {
        //assigment with copy
        std::cout << "assigment with copy" << std::endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    Array &operator=(Array &&other) noexcept { //move assigment
        std::cout << "move assignment" << std::endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

Array create_array(int size) {
    Array ar_copy(size);
    return ar_copy;
}
/* before copy constructor
default constructor - tworzenie ar
default constructor - tworzenie ar_copy w funcji create_array
copy constructor - gdy jest zwracany - wywołany copy con. żeby zrobić kopie ar_copy z funcji
destruktor - usuwamy ar_copy z funkcji
assigment with copy - inicjalizacja kopią ar_copy: ar = create_array(5);
destructor - usuwanie kopii ar_copy
destructor - usuwanie ar
*/

/* with move constructor
default constructor - tworzenie ar
default constructor - tworzenie ar_copy w funcji create_array
move constructor - nie robi się kopia ar_copy, tylko się przekazuje się wskazniki - działa szybciej
destruktor - usuwamy ar_copy z funkcji
assigment with copy - inicjalizacja kopią ar_copy: ar = create_array(5);
destructor - usuwanie kopii ar_copy
destructor - usuwanie ar
*/

/* with move constructor and move assigment
default constructor - tworzenie ar
default constructor - tworzenie ar_copy w funcji create_array
move constructor - nie robi się kopia ar_copy, tylko się przekazuje się wskazniki - działa szybciej
destruktor - usuwamy ar_copy z funkcji
move assigment - inicjalizacja wskaznikiem obiektu ar_copy: ar = create_array(5);
destructor - usuwanie kopii ar_copy
destructor - usuwanie ar
*/



int main() {
    Array ar;
    ar = create_array(5);

    std::cout << std::endl;

    Array ar1 = ar;



    return 0;
}
