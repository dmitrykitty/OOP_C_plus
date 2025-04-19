#include <iostream>

struct Base {
    int x;
    void f() {}
};

struct Derived : private Base {
    int y;

    void g() {
        std::cout << x << '\n'; //tutaj do x jest dostep
    }
};

//------------------------------------------------------------------------

struct Granny {

    friend int main();

    //dalej nie ma dostepu w main do x przez s.x
    //friend pozwala pozbawić się od ograniczen tego, kto ich stworzyl
    //tutaj mama zabrania dostep
    //granny pozwala, ale mama zabrania xD
private:
    int x;
    void f() {}
};

struct Mom : private Granny { //mama zabrania dla wszystkich dostep do granny
    friend struct Son;
    int y;
    void g() {
        std::cout << x << '\n'; //brak dostepu, bo jest private
    }
};

struct Son : Mom {
    int z;

    void h() {
        std::cout << x; // jak będzie struct Mom: private Granny - brak dostepu
    }
};


//---------------------------------------------------------------------------
int main() {
    std::cout << "Hello World!\n";
    Derived d;
    std::cout << d.x << '\n'; //jezeli pole x w Base protected - nie ma dostępu
    //protected dpstepna friend, derived

    //typ dziedziczenie wskazuje, kto widzi ze jestes derived od czegośc.
    //public - widoczne dla wszystkich
    //private - tylko ja oraz moje friends widzą, że nasladuje Base.
    //czyli jakby wszystkie pola rodzica nie są dostepne wszędzie , tylko wewnątrz derived

    //---------------------------------------------------------------------------------------

    Son s;
    s.z; //ok
    s.y; //ok
    s.x; //nie ok CE, bo main zewnętrzna funkcja, ale wewnętrz Son x - ok
}
