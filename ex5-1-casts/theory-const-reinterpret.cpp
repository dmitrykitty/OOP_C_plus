#include <iostream>

int main() {
    //CONST CAST
    int a;
    const int *ptr_a = &a;
    int *ptr_b = const_cast<int *>(ptr_a); //usuwanie modyfikatora const(chcemy, żeby ptr_b był nie const)
    const int *ptr_c = const_cast<const int *>(&a); //dodanie const(chcemy zeby ptr_c był const)
    //mozna cast z &var lub innegi wskaznika

    const double b = 10;
    const double &lnk_b = b;
    auto &lnk_c = const_cast<double &>(lnk_b); //usuwanie modyfikatora const
    const double &lnk_l = const_cast<const double &>(lnk_b); //dodanie modyficatora const
    const double &lnk_c_l = const_cast<const double &>(b); //mozna cast z innej referencji lub zmiennej

    int buff[10] {0};
    const char* data = reinterpret_cast<char*>(buff);

    //CONST CAST TYLKO DLA WSKAZNIKOW I REFERENCJI



    //REINTERPRET CAST
    //bitowe rzutowanie wskaznikow/referencji bez dodatkowego sprawdzania kompilatorem
    int d = 10;
    int *ptr_d = &d;
    char *ptr_ch = reinterpret_cast<char *>(ptr_d);
    char &lnk_ch = reinterpret_cast<char &>(ptr_d);

    struct A {
        int a, b, c;
    };

    struct B {
        int a, b;
    };

    B *b_struct = new B(1, 2);
    A *a_struct_a = reinterpret_cast<A *>(b_struct); //rzutowanie referencji i wskaznikow na struktury
    A &a_struct_b = const_cast<A &>(a_struct_b);
    a_struct_a->c = 18;
    std::cout << a_struct_a->c << std::endl;

    //CONST CAST
    //----------------------------------------------------------------------------------------------------------
    delete a_struct_a;
    const double &pi{3.1415};
    int volume{0};
    double weight{0.0};

    char *ptr_byte = const_cast<char *>(&volume); //nie ok - int -> char

    const float &ptr_pi = const_cast<double &>(pi); //ok
    float *ptr_pi2 = const_cast<double *>(&pi); //nie ok

    const short &lnk_v = const_cast<const int &>(volume); //najpierw cast, pozniej tworzona kopia typu short i na nią
    //wskazuje
    const long &lnk_v = const_cast<const long &>(volume); // nie ok - int -> long
    const double *ptr_w = const_cast<double *>(&weight); // ok - ale tu nie jest potrzebny. mozna
    const double* ptr_w2 = &weight; //var -> const var - ok
    double* ptr_pii = &pi;  //const var -> var nie ok
    double* ptr_pii3 = const_cast<double *>(&pi); //ok, bo usuwamy const za pomoca const cast

    //REINTERPRET CAST
    //-------------------------------------------------------------------------------------------------------------
    class Base { };
    class Derive : public Base { };
    class Line { };

    Derive* ptr_drv = new Derive();
    int dist {0};
    double price {0.0};
    const int meter {1000};

    Base* ptr_g = reinterpret_cast<Base *>(ptr_drv); //to samo
    Base* ptr_g1 = ptr_drv; //ok, tez dzaiła, bo robimy upcast

    Line* ptr_ln = reinterpret_cast<Line *>(ptr_drv); //prawdopodobnie UB, bo razne typy
    Line* ptr_ln1 = ptr_drv; //juz nie ok, razne niezwiazane typy

    int* lnk_pr = reinterpret_cast<int *>(&meter); //nie usuwa const
    int& lnk_dist = reinterpret_cast<int & >(dist);
    int& lnk_dist2 = dist; //tez dzaiłą, reinterpret cast jest zbędny

    const double& lnk_prt = reinterpret_cast<const double& >(price);//ale może dodac const, rzutowanie jest zbędne
    const double& lnk_ptr2 = price; //oki doki

    //--------------------------------------------------------------------------------------------------------------

    return 0;
}
