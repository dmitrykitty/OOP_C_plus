#include <iostream>
#include <ostream>

int main() {
    char c[] = {1, 2, 3, 4, 5, 6, 7, 8};
    short* p = reinterpret_cast<short*>(c);
    std::cout << *p << std::endl;

    //513 Big Indian, Little Indian
    //1*1 + 2^8 * 2
    //jak by był int
    //1*2^0 + 2 * 2^8 + 3 * 2^16 + 4*2^24
}
