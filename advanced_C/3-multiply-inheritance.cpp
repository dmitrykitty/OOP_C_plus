#include <iostream>
#include <ostream>

struct Granny {
    int g;
};

struct Dad: virtual public Granny{
    int x;
};

struct Mom: virtual public Granny {
    int y;
};

struct Son :  public Dad, public Mom {
    int z;

};

/*w pamieci:
  |x|y|z|,czyli syn zaczyna sie 4 baity wczesniej niz Mom:
  |
p(son)
jak robimy cast z Syna do Mom, wskaznik sie przesunie o 4 baity;
*/

int main() {
    Son s;
    Son* ptr_son = &s;
    Mom* ptr_mom = new Mom;
    Dad* ptr_dad = new Dad;
    Granny* ptr_granny = new Granny;
    std::cout << ptr_granny << " " << ptr_son <<  std::endl;
    static_cast<Son*>(ptr_dad); //działa
    static_cast<Son*>(ptr_mom); //działa
    static_cast<Son*>(ptr_granny); //nie dzaiła, czyli w dół nie zbyt działa


    Mom* ptr_mom = &s; //czyli tutaj przesuniecie o 4 baity do przodu, bo obiekt Mom zaczyna sie poźniej
    std::cout << ptr_son << " " << ptr_mom << std::endl;
    std::cout << sizeof(s) << std::endl;

    return 0;
}