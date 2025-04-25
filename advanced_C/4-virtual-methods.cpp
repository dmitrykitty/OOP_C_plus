#include  <iostream>

struct Base {
    virtual void f() const {
        std::cout << 1 << std::endl;
    }

    virtual ~Base() = default;
};

struct Derived : Base {
    void f() const override {
        //override nie przeciaza funkcji, tylko mowi kompilatorowi ze ta funkcja ma byc overloadded i jak
        std::cout << 2 << std::endl;
    }

    void f() {
        //jakb by nie było funkcji wyżej - było by wypisane 1, bo signatura się nie zgarda
        //i ta funkcja f jest zupelnie inną funkcją
        std::cout << 3 << std::endl;
    }
};

//-----------------------------------------------------------------------------------

struct Granny {
    virtual void f() const {
        std::cout << 10 << std::endl;
    }

    virtual ~Granny() = default;
};

struct Mom : Granny {
private:
    void f() const override {
        std::cout << 20 << std::endl;
    }

    void g() {};
};

struct Son : Mom {
    void f() const final {
        std::cout << 30 << std::endl;
    }
};

//-----------------------------------------

struct Base1 {
    virtual void f() {
        std::cout << 100 << std::endl;
    }

    virtual ~Base1() = default;
};

struct Base2 {
    virtual void f() {
        std::cout << 200 << std::endl;
    }

    virtual ~Base2() = default;
};

struct Derived1 : Base1, Base2 {
    void f() override {
        std::cout << 300 << std::endl;
    }
};

int main() {
    Derived d;
    Base *ptr_base = &d;
    ptr_base->f(); //2

    //--------------------------------

    Mom m;
    Granny *ptr_granny = &m;
    ptr_granny->f(); //20 - prywatnosc - compile time, a wybór funkcji
    //virtualnej - run time, więc prywatność nie wpływa na wynik
    //ale jakby f() była private u Granny - CE, bo przez Granny nie mamy dostepu do virtualnej funkcji

    //------------------------------------------------------------------------------------------------
    Derived1 d3;
    Base1 &b1 = d3;
    Base2 &b2 = d3;
    b1.f(); //300
    b2.f(); //300, a jak by była nie virtualna - 200
}
