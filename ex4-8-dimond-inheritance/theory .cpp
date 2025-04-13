class MegaBase {
protected:
    MegaBase() = default; //zabronienie tworzenia obiektow MegaBase(dla nieabstraktych klas)

public:
    size_t size;

    ~MegaBase() = default;

private:
    void f() {};
};

class Base : virtual public MegaBase {
protected:
    int x{};
};

class Base2 : virtual public MegaBase {
protected:
    int y{};
public:
    ~Base2() = default;
};

class Derived : public Base, public Base2 {
protected:
    ~Derived() override = default;

public:
    void f() {}
};

int main() {
    Derived d;
    d.f(); //problem, bo metody maja taki samy nazwe w Base i Base1
    d.Base::f(); //w taki sposob zadziała
    //lepiej zmienic imie

    //diamond inheritance - kazda zmienna lub metod klasy bazowej jest dwa razy w klasie najnizszej
    //teraz obiekt klasy derived ma w sobie dwokrotnie zmenne klasy megabase i jednokrotnie klas base
    //rozwiazanie - virtual inheritqance for Megabase - tworzona tylko jedna kopia

    //zeby zabronic tworzenie obiektu w stacku przez Derived d - dajemy destruktor do sekcji protected
    //wtedy moż na tworzyc obiekty tylko za pomocą Derived d = new ...
    //zeby usunąć - piszemy wewnatrz klasy static method with delete static void delete(Line* ptr)
}
