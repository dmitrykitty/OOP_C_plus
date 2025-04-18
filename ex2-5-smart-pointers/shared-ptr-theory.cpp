#include <array>
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr{std::make_shared<int>(15)}; //nullptr
    std::shared_ptr<int> ptr2{}; //nullptr
    std::shared_ptr<int> ptr3{ptr}; //wskazuja na ta sama pamiec

    ptr2 = ptr3;
    *ptr3 = 7;
    std::cout << ptr2 << " " << *ptr2 << std::endl;
    //sumowac odejmowac smart pointers nie mozna
    //wewnątrz z każdym adresem pamięci na ktory wskazuje shared ptr
    //- counter ktory liczy ilosc wskaznikow na adres pamieci.
    //jak jakis ze wskaznikow zmienia adres - counter--
    //kiedy counter = 0 - usuwanie obiektu

    //----------------------------------------------------------------------------
    int* p = ptr.get(); //raw pointer
    ptr2.reset(p); //zmienia adres na nullptr lub na to co jest wskazane
    ptr2.swap(ptr); //swapuje wskaznii
    bool is_one = ptr3.unique(); //zwraca true, jak jest tylko jeden wskaznil na ten adres
    int count_of_ptrs = ptr3.use_count(); //zwraca wartosc counter
    std::cout << count_of_ptrs  << " " << is_one << std::endl;
    ptr3 = std::make_shared<int>(15);

    ptr2.reset(new int[5]{1, 2, 3});

    int* ar = ptr2.get();
    for (int i = 0; i < 5; i++) {
        std::cout << *(ar + i) << std::endl;
    }

    int array[5] = {2, 4, 6, 8, 10}; // pełna inicjalizacja

    // Alokacja nowej tablicy na stercie i skopiowanie danych
    std::shared_ptr<int[]> ptr4 = std::make_shared<int[]>(5); //nie działa, ale dzaiła z unique_ptr
    for (int i = 0; i < 5; ++i) {
        ptr4[i] = array[i];
    }

    // Wypisanie zawartości
    for (int i = 0; i < 5; ++i) {
        std::cout << ptr4[i] << " ";
    }



    std::shared_ptr<float> p_3 {new float()}; //ok
    std::shared_ptr<float> p_2 = new float(); //nie ok


}
