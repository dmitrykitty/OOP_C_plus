#include <iostream>

struct Point {
    int x;
    double y;

    void f(int z) {
        x += z;
    }
};

int main() {
    std::cout << "Hello World!\n";


    Point p1{1, 3.14};
    Point* ptr_p = &p1;
    int Point::* ptr = &Point::x; //point to field x
    p1.*ptr = 5;

    std::cout << p1.*ptr << '\n';

    void (Point::* f_ptr)(int) = &Point::f;
    (p1.*f_ptr)(7);
    std::cout << p1.*ptr << '\n';

    (ptr_p->*f_ptr)(7);
    std::cout << ptr_p->*ptr << '\n';


    return 0;
}
