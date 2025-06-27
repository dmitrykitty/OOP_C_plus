#include <iostream>

template<typename T>
void f(T x) {
    std::cout << 1;
}

void f(int x) {
    std::cout << 2;
}

//im dokładniej jest opisana sygnatura funkcji, będzie ona wywołana
//pisząc wybor typu w <> - będzie wywołana template wersja
//szablony o jednakowych sygnaturach, ale roznych zwracanych typach się kompilują,
//ale nie da się je wywołać

template<typename T>
void g(const T& x) {
    std::cout << 1;
}

template<typename T>
void g(T& x) {
    std::cout << 2;
}

//-----------------------------------specialization----------------------------------------
template<typename T>
class vector {
    T* arr;
};

//pełna specjalizacja
template<>
class vector<bool> {
    char* arr;
};

//-----------------------------------------
template<typename T, typename U>
struct S {};

//częściowa specjalizacja
template<typename T>
struct S<T, T> {};

template<typename T>
struct S<int, T> {};

//------------------------------------------

template<typename W>
struct A {
    A() = delete; //zeby sprawdzic jaki typ bedzie wywołany
};

//dla wszystkich obiektow tworzonych przez referencje inny specjalizacja(czesciowa specjalizacja)
template<typename W>
struct A<W &> {
    A() = delete;
};

template<typename W>
struct A<const W> {
    A() = delete;
};


// --------------------------function TEMPLATE specialization--------------------------------
template<typename T, typename U>
void m(T, U) { std::cout << 1; }

//u funkcji jest tylko pełna specjalizacja


//overloading - najpierw wybierana funkcja przeciazona, a pozniej specjalizacja
//czyli w tym przypadku wybierany drugi template i u niego jest specjalizacja, wiec bedzie wybrany 3.
//w innym przypadku najbardziej pasujaca przeciazona funkcja - 2 i będzie ona wybrana
template<typename T>
void m(T, T) { std::cout << 2; }

template<>//spec
void m(int, int) { std::cout << 3; }


//overlod ->spec






int main() {
    int x = 0;
    f(x); //będzie wywołana 2 funkcja

    g(x); //2, ale jak bedzie w drugiej T x - juz CE -> miedzy const T& i T CE, miedzy const T i T - CE
    const int& y = x;
    g(y); //1
    S<double, double> s; //CE, bo nie ma lepszej

    //A<const int&> a; //A<W&> - referencja ma priorytet

    long r = 0;
    m(0, r); //1
    m(0, 0); //bedzie wypisane to, co jest na samym koncu 2/3
}
