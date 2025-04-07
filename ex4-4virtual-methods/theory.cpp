#include <iostream>

class Base {
public:
    void printf(double) {
        std::cout << 1;
    }

    virtual void f(double) {
        std::cout << 3;
    }
};

class Derived : public Base {
public:
    using Base::f;

    void printf(double) {
        std::cout << 2;
    }

    void f(double) override {
        std::cout << 4;
    }
};

int main() {
    Derived d;
    d.printf(1.0); //metoda clas derived
    d.Base::printf(1.0); //metoda clasy Base(tylko jak jest private)
    d.f(1.0);
    //jak mamy using - pierwszenstwo wszystko jedno ma funkcja z klasu Delivered, ale jak przymuja rozne typy
    //- juz ta, ktora ma odpowiedni typ

    Base* b = new Derived();
    b->printf(1.0); //1 - brak dostępu do metod klasy Derived, mimo, że tworze obiekt Derived przez klasę Base
    b->f(1.0); //4 - poniewaz metoda f jest virtual i metoda z klasy Base przesłania się - wywoływana metoda z klasy
    //Derived

    delete b;
    return 0;
}
