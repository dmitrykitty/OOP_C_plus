#include <iostream>

class Array {
    int *data{nullptr};
    size_t size{0};

public:
    Array() = default;

    Array(int *d, size_t length) {
        set_data(d, length);
    }

    void set_data(int *d, size_t length) {
        delete[] data;
        size = length;
        data = new int[size];

        for (size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    Array operator+(const Array &other);

    Array &operator=(const Array &other);


    int *get_data() { return data; }

    size_t get_size() const { return size; }

    ~Array() {
        delete[] data;
    }
};

Array Array::operator+(const Array &other) {
    if (other.data == nullptr)
        return *this;

    size_t new_size = size + other.size;
    int *temp = new int[new_size];

    for (int i = 0; i < new_size; i++) {
        if (i < size)
            temp[i] = data[i];
        else
            temp[i] = other.data[i - size];
    }
    Array ar(temp, new_size);
    delete[] temp;
    return ar;
}

Array &Array::operator=(const Array &other) {
    if (this == &other)
        return *this;

    delete[] data;

    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;
}

int main() {
    int d1[3] = {1, 2, 3};
    int d2[4] = {1, 2, 3, 4};

    Array ar1(d1, 3), ar2(d2, 4);
    Array ar3 = ar1 + ar2;
    std::cout << ar3.get_size() << std::endl;
    for (int i = 0; i < ar3.get_size(); i++)
        std::cout << ar3.get_data()[i] << std::endl;


    return 0;
}
