#include <iostream>

class DeskTop {
    int width{0}, height{0};
    static DeskTop* instance;
    DeskTop(int w, int h): width(w), height(h){ }
public:
    DeskTop(const DeskTop&) = delete;

    static DeskTop* get_instance(int w, int h){
        if(!instance)
            instance = new DeskTop(w, h);
        return instance;
    }

    int get_width(){ return width; }
    int get_height(){ return height; }

    ~DeskTop(){ instance = nullptr; }
};

DeskTop* DeskTop::instance = nullptr;

int main(void)
{
    DeskTop* ptr_desk = DeskTop::get_instance(200, 50);

    delete ptr_desk;

    return 0;
}