#include <iostream>
class Rectangle{
    short x0 {0}, y0 {0}, x1 {0}, y1 {0};
    int border_color {0};
    int fill_color {255};
public:
    Rectangle(short x0=0, short y0=0, short x1=0, short y1=0): x0(x0), y0(y0), x1(x1), y1(y1){}
    int get_border_color(){ return border_color; }
    int get_fill_color(){ return fill_color; }
    void get_coords(short& x0, short& y0, short& x1, short& y1){
        x0 = this->x0;
        y0 = this->x0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(short x0, short y0, short x1, short y1){
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    void set_border_color(int color){ border_color = color; }
    void set_fill_color(int color){ fill_color = color; }

    Rectangle& operator=(const Rectangle& other){
        x0 = other.x0;
        y0 = other.y0;
        x1 = other.x1;
        y1 = other.y1;
        return *this;
    }

};

int main(){
    auto* ptr = new Rectangle();
    ptr->set_coords(1, 2, 10, 20);
    delete ptr;

}
