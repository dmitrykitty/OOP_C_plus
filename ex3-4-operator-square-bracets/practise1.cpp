#include <iostream>

class PointND {
    class Item {
        PointND *curr{};
        int index{-1};

    public:
        Item(PointND *curr, int index) : curr(curr), index(index) {}

        int operator=(short right) const;

        operator int() const;
    };

    short *coords{nullptr}; // координаты точки
    size_t dims{0}; // число координат
public:
    PointND() = default;

    PointND(short *cds, size_t len) : dims(len) {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }
    PointND(const PointND& other): coords(new short[other.dims]{}), dims(other.dims){
        for(int i = 0; i < dims; i++)
            coords[i] = other.coords[i];
    }

    ~PointND() { delete[] coords; }

    Item operator[](int index) { return Item(this, index); }

    PointND &operator=(PointND other) {
        swap(other);
        return *this;
    }

    void swap(PointND &other) noexcept {
        std::swap(coords, other.coords);
        std::swap(dims, other.dims);
    }
};

int PointND::Item::operator=(short right) const {
    if (index < 0 || index >= curr->dims) return 0;
    curr->coords[index] = right;
    return right;
}

PointND::Item::operator int() const {
    if (index < 0 || index >= curr->dims) return 0;
    return curr->coords[index];
}
