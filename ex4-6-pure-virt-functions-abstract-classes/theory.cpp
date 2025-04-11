#include <iostream>

struct Base {
    virtual void print() = 0;

    virtual ~Base() = default;
};

//wszystko jedno mozna zrobic funkcje klasy Bazowej print,
//kiedy np zapomnięto override print w klasie Derived - niech wypisuje błąd

void Base::print() {
    std::cout << "Error of overriding" << std::endl;
}

struct Derived : Base {
    void print() override {
        std::cout << "Derived::print" << std::endl;
    }
};

int main() {
    Derived d;
    Base& base = d;
    std::cout << typeid(base).name(); //typeid pkazuje, jaki rzeczywiscie typ leży pod referencja typu
    //Base(7Derived - tak odcvzytuje kompilator), żeby imie z kodu w terminalu c++filt -t 7Derived

    Derived *pd = dynamic_cast<Derived *>(&base); //zwraca null ptr jak w base był jednak nie Derived
    //zmiena typu w RunTime - czyli dodatkowo przechowywana jakas informacja w Vtable
    //dynamiccast tylko dla klasow polimorfnych(moze robic cast w bok i dol)
    //RTTI - ruttime type information - dodatkowe info, przechowywane w Vtable oprocz vptr
    if (pd) {
        //do sth
    }


}
