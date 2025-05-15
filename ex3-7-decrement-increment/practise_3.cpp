#include <iostream>

class PointND {
    short* coords{nullptr}; // координаты точки
    size_t dims{0}; // число координат

public:
    PointND() = default;

    PointND(short* cds, size_t len) : dims(len) {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }

    ~PointND() { delete[] coords; }

    short operator[](int index) const {
        if (index > 0 && index < dims)
            return coords[index];
        return 0;
    }

    short& operator[](int index) {
        static int error = 0;
        if (index > 0 && index < dims)
            return coords[index];
        return error;
    }

    void swap(PointND& rhs) noexcept {
        std::swap(coords, rhs.coords);
        std::swap(dims, rhs.dims);
    }

    PointND& operator=(PointND rhs) {
        swap(rhs);
        return *this;
    }

    PointND& operator++() {
        for (size_t i = 0; i < dims; ++i)
            coords[i] = coords[i] + 1;
        return *this;
    }

    PointND operator++(int) {
        PointND tmp = *this;
        ++*this;
        return tmp;
    }

    PointND& operator--() {
        for (size_t i = 0; i < dims; ++i)
            coords[i] = coords[i] - 1;
        return *this;
    }

    PointND operator--(int) {
        PointND tmp = *this;
        --*this;
        return tmp;
    }

    PointND& operator+=(const PointND& rhs) {
        if (dims == rhs.dims)
            for (size_t i = 0; i < dims; ++i) {
                coords[i] = coords[i] + rhs.coords[i];
            }
        return *this;
    }

    PointND& operator-=(const PointND& rhs) {
        if (dims == rhs.dims)
            for (size_t i = 0; i < dims; ++i) {
                coords[i] = coords[i] - rhs.coords[i];
            }
        return *this;
    }
};

int main() {}
