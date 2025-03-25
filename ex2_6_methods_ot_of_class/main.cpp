#include "PointND.h"

int main()
{
    PointND pt(5);
    std::cout << PointND::get_counter() << std::endl;
    PointND pt2 {pt};
    std::cout << PointND::get_counter() << std::endl;
    PointND pt3(5);
    std::cout << PointND::get_counter() << std::endl;
    pt3 = pt;


    return 0;
}