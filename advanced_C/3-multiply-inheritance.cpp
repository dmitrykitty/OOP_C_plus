#include <iostream>
#include <ostream>

struct Dad {
    int x;
};

struct Mom {
    int y;
};

struct Son : public Dad, public Mom {
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

    Mom* ptr_mom = &s; //czyli tutaj przesuniecie o 4 baity do przodu, bo obiekt Mom zaczyna sie poźniej
    std::cout << ptr_son << " " << ptr_mom << std::endl;

    return 0;
}