#include <iostream>

class Box3D {
    short a{}, b{}, c{};
    short error{};

    class Item {
        Box3D *box;
        int index{-1};

    public:
        Item(Box3D *box, int index) : box(box), index(index) {}

        short operator=(short right) const {
            if (right < 0) return box->error;
            if (index == 0) box->a = right;
            if (index == 1) box->b = right;
            if (index == 2) box->c = right;
            return box->error;
        }

        operator short() const {
            if (index == 0) return box->a;
            if (index == 1) return box->b;
            if (index == 2) return box->c;
            return box->error;
        }
    };

public:
    Box3D() = default;

    Box3D(short a, short b, short c) : a(a), b(b), c(c) {}

    void get_dims(short &a, short &b, short &c) const {
        a = this->a;
        b = this->b;
        c = this->c;
    }

    void set_dims(short a, short b, short c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    Item operator[](int index) { return {this, index}; }

    operator int() const { return a * b * c; }
};
