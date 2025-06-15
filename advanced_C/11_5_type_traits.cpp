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
//-------------REMOVE_REFERENCE----------------------
//zwraca typ bez referencji, pointera, const
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

//----------------REMOVE_CONST-------------------------------
template <typename T>
struct remove_const {
    using type = T;
};

template <typename T>
struct remove_const<const T> {
    using type = T;
};
//difference between remove_const i const_cast
//w czasie kompilacji i działa tylko dla typow szablonu, a const cast z wartosciami(pointer, reference)

//------------------STD::CONDITIONAL----------------------------------
template <bool B, typename T, typename F>
struct conditional {
    using type = F;
};
template <typename T, typename F>
struct conditional<true, T, F> {
    using type = const T;
};

template <bool B, typename T, typename F>
using conditional_t = typename conditional<true, T, F>::type;
//szablonowe usingi pozwalajace nie pisac typename ...::type


int main() {
    return 0;
}