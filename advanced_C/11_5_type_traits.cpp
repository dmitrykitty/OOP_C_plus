#include <iostream>

//Metafunctions and type traits
template<typename T, typename U >
struct is_same {
    static constexpr bool value = false;  //domyślnie false dla różnych typów
};

template<typename T>
struct is_same<T, T> {
    static constexpr bool value = true;  //specjalizacja dla identycznych typów
};

template <typename T, typename U>
void f(const T& x, const U& y) {
    //...
    if (typeid(x) == typeid(y)){ //...
        //run time check
    }
    //...
    if constexpr (is_same<T, U>::value) {
        //constexpr tutaj by if sie wyliczał w czasie kompilacji, bo is_same juz sie wlicza w czasie kompilacji
        //jak jest false-kod nawet sie nie generuje, co pozwala skompilowac program. bez tego -> CE
        x = y;

        //do something ...
    }
}
//-------------------------------------------------

template <typename T>
struct remove_reference {
    using type = T;
};

template <typename T>
struct remove_reference<T&> {
    //specjalizacja dla T&
    using type = T;
};

template <typename T>
void f() {
    typename remove_reference<T>::type x;
    //a mozna dodac jeszcze using
    using no_ref_type = typename remove_reference<T>::type;
    no_ref_type y = 5;
    //typename, bo type jest typen, a nie statycznym olem klasy
}

int main() {
    return 0;
}