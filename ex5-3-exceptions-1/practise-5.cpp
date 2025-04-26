//
// Created by Lenovo on 26/04/2025.
//

#include <iostream>


class Vector3D {
    enum { min_coord = -100, max_coord = 100 };

    int x{}, y{}, z{};

public:
    Vector3D() = default;

    Vector3D(int x, int y, int z) {
        if (x < min_coord || x > max_coord || y < min_coord || y > max_coord || z < min_coord || z > max_coord)
            throw -2;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void get_coords(int& x, int& y, int& z) const {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    void set_coords(int x, int y, int z) {
        if (x < min_coord || x > max_coord || y < min_coord || y > max_coord || z < min_coord || z > max_coord)
            throw -1;

        this->x = x;
        this->y = y;
        this->z = z;
    }

    int& operator[](int index) {
        if (index < 0 || index > 2)
            throw "Incorrect index.";
        if (index == 0) { return x; }
        if (index == 1) { return y; }
        return z;
    }

    const int& operator[](int index) const {
        if (index < 0 || index > 2)
            throw "Incorrect index.";
        if (index == 0) { return x; }
        if (index == 1) { return y; }
        return z;
    }
};

int main() {
    try {
        Vector3D v3(10, 1000, -500);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    } catch (int er) {
        std::cout << er << std::endl;
    }

    return 0;
}
