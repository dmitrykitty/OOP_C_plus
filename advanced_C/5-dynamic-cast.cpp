#include <iostream>
//DYNAMIC_CAST, RTTI(Run Time Type information)

class Base {
public:
    int x;
    virtual double area() = 0;
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    double area() override {
        return y * y;
    };
    int y;
};

int main() {

    Derived d;
    std::cout << sizeof(d) << std::endl;
    Base* p = &d;

    auto* pd = dynamic_cast<Derived*>(p);
    //static cast zwroci UB jak tam był nie Derived,
    //a dynamic cast da error Bad_cast dla referencji, a jak cast do wskaznika - nullptr
    //dynamic cast wdoł działa tylko dla polimorfic types
    //w RunTime mamy RTTI to make the cast

    auto* ppdf = dynamic_cast<void*>(pd);
    //mozna zawsze robic dynamic cast do void* od polimorfnego typu
    //w taki sposob mozna sprawdzic czy typ jest polimorfny

    //uppcast mozna robic zawsze, nawet jak typ nie jest polimorfny

    //dynamic cast rowniz moze robic cast w bok - od matki do ojca(jezeli matka jest polimorfna)
    //bo wiadomo na il przzesunac wskaznij by dojsc do ojca

    //mozna w if
    if (auto* ppd = dynamic_cast<Derived*>(p); ppd) {
        std::cout << typeid(*ppd).name() << std::endl; //7Derived, a jak pointer - P7Derived
        //typeid dziala i dla nie polimorfnych typow
        //c++filt -t (zwroci prawdziwe imie bez długosci)
        //w dynamic_cast typeid są sprawdzane na rownosc zeby zrobic cast
    }
    //robimy cast, sprawdzamy na nullptr i jak ok - wchodzimy do if

    //przypaski, gdzy casty daja rozne wyniki
    /*
     cast w bok:
     DownCast z virtualnym inheritance od polimorfnego przodka:
        static cast - CE
        dynamic cast - OK
        reinterpret cast - UB
    */
    //virtualna funkcja to taka z ktorej mozemy skorzystac przez virtualnego przodka lub
    //wybor jaką wersje virtualnej wynkcji wybrac nastepuje w RunTime



    return 0;
}