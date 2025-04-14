int main() {

    //STATIC CAST
    //------------------------------------------------------------------------------------------------------------------

    class Base { };
    class Derive : public Base { };
    class Line { };
    class Derived2 : public Derive { };

    Base* ptr_b = new Derive();
    Derived2* ptr_ln = static_cast<Derived2*>(ptr_b); //downcast not good, ale cuż

    Base* ptr_base {nullptr};
    int var {10};
    double price {0.0};
    double& lnk_d = price;

    int* ptr_v = static_cast<int *>(&var); //cast zbędny
    int* ptr_v2 = &var;

    double& lnk_dat = static_cast<double & >(price); //cast zbędny
    auto& lnk_dat2 = price;

    Derive* ptr_drv = static_cast<Derive *>(ptr_base); //downcast - ok
    Derive* ptr_drv = static_cast<Derive *>(100); //nie ok - int i Derive - niezwiązane typy
    Line* ptr_ln = static_cast<Line *>(ptr_base); //nie ok - Line i Base - niezwiązane typy

    const double& lnk_cnst_d = static_cast<double & >(lnk_d);
    const auto& lnk_cnst_d2 = &lnk_d; //cast zbędny

    Base base;
    long& data = static_cast<long& >(var); //nie ok - int -> long&

    double var_d = static_cast<double>(lnk_d);
    double var_d2 = lnk_d; //cast zbędny

    short data_1 = static_cast<short>(var); //ok
    Derive* ptr_drv2 = static_cast<Derive *>(&base); //downcast - lepiej nie robic, ale ok

    const char data6 = static_cast<const char>(var); //ok, static cast tez moze dodawac const
    Line* ptr_ln3 = static_cast<Line *>(&base); //niezwiązane obiekty
    char* buff = static_cast<char *>(price); //nie ok - double->char*



    //-----------------------------------------------------------------------------------------------------------------

    return 0;
}