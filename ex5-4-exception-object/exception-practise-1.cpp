#include <iostream>

class IndexError {};

class PointND {
    double* coords{nullptr}; // координаты точки
    size_t dims{0}; // число координат
public:
    PointND() = default;

    PointND(const PointND& other): coords(new double[other.dims]), dims(other.dims) {
        for (int i = 0; i < dims; i++)
            coords[i] = other.coords[i];
    }

    PointND(const double* cds, size_t len) : dims(len) {
        coords = new double[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }

    PointND& operator=(PointND other) {
        swap(other);
        return *this;
    }

    const double& operator[](size_t i) const {
        if (i >= dims)
            throw IndexError();
        return coords[i];
    }

    double& operator[](size_t i) {
        if (i >= dims)
            throw IndexError();
        return coords[i];
    }

    //pomocniczy funkcja swap dla operator=
    void swap(PointND& other) noexcept {
        std::swap(coords, other.coords);
        std::swap(dims, other.dims);
    }

    ~PointND() { delete[] coords; }

    [[nodiscard]] size_t get_dims() const { return dims; }
};


int main() {
    double coords[]{0.1, 0.2, 0.5, -1.4};
    PointND pnt(coords, std::size(coords));


    return 0;
}
