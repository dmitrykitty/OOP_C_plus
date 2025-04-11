#include "Point.h"
#include <iostream>

int main(void)
{
    Point::set_bounds(-100, 100);
    Point pt(-5, 7);
    std::cout << pt.get_x() << " " << pt.get_y() << std::endl;
    int left, right;
    Point::get_bounds(left, right);
    std::cout << left << " " << right << std::endl;



    return 0;
}