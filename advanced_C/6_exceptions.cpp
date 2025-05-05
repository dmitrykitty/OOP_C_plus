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
    segmentation fault
    stack overflow
___________________________________________________________________
Hierarchia:
-Logic error(winny jest uzytkownik)
-Runtime error(cos poszło nie tak)
 */
int main() {
    try {
        divide(3, 0);
    } catch (std::logic_error& err) {
        std::cout << err.what() << std::endl; //what(virtualna funkcja)  - zwraca const chat* - tekst of exception
    }

    return 0;
}