#include <iostream>

class PointND {
    short* coords{nullptr}; // координаты точки
    size_t dims{0}; // число координат
    short error = 0;

public:
    PointND() = default;

    PointND(const PointND& other): dims(other.dims) {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = other.coords[i];
    }

    PointND(short* cds, size_t len) : dims(len) {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }

    ~PointND() { delete[] coords; }

    short operator[](int index) const {
        if (index >= 0 && index < dims)
            return coords[index];
        return 0;
    }

    short& operator[](int index) {
        if (index >= 0 && index < dims)
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
            ++coords[i];
        return *this;
    }

    PointND operator++(int) {
        PointND tmp = *this;
        ++*this;
        return tmp;
    }

    PointND& operator--() {
        for (size_t i = 0; i < dims; ++i)
            --coords[i];
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

    size_t get_dims() const { return dims; }
};

int main() {
    short coords[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    PointND point(coords, std::size(coords));
    std::cout << point[12] << std::endl;
}
