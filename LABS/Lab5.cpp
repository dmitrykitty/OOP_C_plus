#include <iostream>
//pusta klasa zajmuje 1 bait
//poczytać o cashline

//wymiar
/* char 1
 * short <= int <= long
 * long long 8+
 */

//set na podstawie drzewa black red
//szybkosc wyszukiwania O(logn)
//

//mamy plik z liczbami od 0 do 1000 na 100gb
//100 gb / 2b(wymiar short)
//mamy posortować

class C { // wymiar 24
  char c;
  double d;
  int i;
};

class B { // wymiar 16
  double d;
  int i;
  char c;
};

int main() {
  std::cout << sizeof(C) << std::endl;
  std::cout << sizeof(B) << std::endl;
  int a{5}, b{10};
  int temp{};
  temp = a;
  a = b;
  b = temp;
  return 0;
}