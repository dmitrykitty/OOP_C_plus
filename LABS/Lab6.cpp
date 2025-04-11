class B {
public:
    virtual void f();
    virtual ~B() = default;
};

class D : public B {
public:
    void f() override;

};
//D d;
//B b = d; wywołany kosntruktor kopijuący (slising) tutaj!!!! - nie jest polimorfizm
//b.f();

//B* b = new D();
//b->f();
//delete b;

//B& b = d;
//b.f();

//
