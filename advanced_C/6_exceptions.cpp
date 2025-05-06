#include <iostream>
#include <ostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0)
        throw std::logic_error("Divide by zero");
    return a / b;
}

//wyjątki - runtime rzecz
/*co rzuca wyjątki:
4 operatory:
* new - jak nie udało się uzyskac pamiec -> wyjątek std::bad_alloc
* dynamic cast do referencji -> wyjątek std::bad_cast
* typeid() -> bad_typeid kiedy od nullptr
* throw xD
__________________________________________________________________
Difference between runtime errors and exceptions:
    segmentation fault nie jest exception
    exceptions dwoch poziomow:
    - processora
    - C++
    dzielenie na 0 nie jest exception poziomu C++, tylko poziomu processora (floating point exception (core dumped))
    segmentation fault (stack overflow, array out of bounds, nullptr dereference)
    aborted(uncaught exception -> terminate() -> abort(), pure virtual function call)

___________________________________________________________________
Hierarchia:
-Logic error(winny jest uzytkownik)
-Runtime error(cos poszło nie tak)

___________________________________________________________________
RAII - Resource Acquisition Is Initialization

Wydzialamy pamiéc i coś rzuca wyjątek i nie robimy delete
dla dynamicznie wydzielonej pamięci
otwieranie plikow
 */

//robimy wrapper ktory będzie usuwał nie usunięte obiekty
//teraz wyżej stosujemy Wrapper(Unique PTR)
struct SmartPTR {
    int* links;
    explicit SmartPTR(int* links): links(links) {}

    SmartPTR(const SmartPTR&) = delete; //zabraniamy copy, żeby nie było podwojnego delete
    SmartPTR& operator=(const SmartPTR&) = delete; //tu to samo
    //trzeba jeszcze dodac move constructor
    ~SmartPTR() { delete links; }
    int& operator*() const { return *links; }
};

void g(const SmartPTR& ptr) {
    if (*ptr == 0)
        throw 1;
}

void f(int x) {
    SmartPTR wp(new int(x)); //zamiast linijki niżej
    //int* p = new int(x);
    g(wp);
}


int main() {
    try {
        divide(3, 0);
    } catch (std::logic_error& err) {
        std::cout << err.what() << std::endl; //what(virtualna funkcja)  - zwraca const chat* - tekst of exception
    }

    return 0;
}
