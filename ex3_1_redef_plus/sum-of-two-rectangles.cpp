#include <iostream>

class Rectangle {
    int x0{0}, y0{0}, x1 {0}, y1 {0};
public:
    Rectangle(int x0=0, int y0=0,  int x1=0, int y1=0): x0(x0), y0(y0), x1(x1), y1(y1){}

    void get_coords(int& x0, int& y0, int& x1, int& y1)const {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }

    void set_coords(int x0, int y0, int x1, int y1){
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    Rectangle operator+(const Rectangle& right) const {
        int new_x0 = x0 < right.x0 ? x0 : right.x0;
        int new_y0 = y0 < right.y0 ? y0 : right.y0;
        int new_x1 = x1 > right.x1 ? x1 : right.x1;
        int new_y1 = y1 > right.y1 ? y1 : right.y1;
        return Rectangle(new_x0, new_y0, new_x1, new_y1);
    }
};
