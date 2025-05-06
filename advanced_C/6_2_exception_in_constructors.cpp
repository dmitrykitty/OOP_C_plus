#include <iostream>

struct A {
    A() { std::cout << "A" << std::endl; }
    ~A() { std::cout << "~A" << std::endl; }

};

struct S {
    A a;
    S(int x) {
        std::cout << "S" << std::endl;
        if (x ==0) throw 1;
    }
    ~S() { std::cout << "~S" << std::endl; }
};

/*
A - tworzenie obiektu A
S - tworzeni obiektu S
~A - usunięcia A jako pola S
Caught - exception(obiekt S nie był stworzony do końca)
zeby opracowac exception w liscie inicjalizacji - function try block

*/

struct B {
    B(int x) {
        std::cout << "B" << std::endl;
        if (x == 0) throw 1;
    }
    ~B() { std::cout << "~B" << std::endl; }
};

/*
B - tworzenie b1
B - tworzenie b2
~B -usunięcie b1
Caught -b2 orak b3 oraz k nie jest stworzony
Caught
Exception w liscie inicjalizacji K, czyli obiekt K nie jest stworzony
try przed:
*/

struct K {
    B b1;
    B b2;
    B b3;
    K(int x)try: b1(1), b2(x), b3(1) {
        std::cout << "K" << std::endl;
    } catch (...) {
        std::cout << "Caught" << std::endl;
    }
    ~K() {
        std::cout << "~K" << std::endl;
    }
};

int main() {
    try {
        S s(0);
    } catch (...) {
        std::cout << "Caught" << std::endl;
    }

    try {
        K k(0);
    } catch (...) {
        std::cout << "Caught" << std::endl;
    }
}