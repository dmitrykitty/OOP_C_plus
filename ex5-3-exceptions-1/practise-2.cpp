#include <iostream>


class ArrayInt {
    int* data{};
    size_t size{};


public:
    ArrayInt() = default;

    ArrayInt(int* d, size_t s) {
        size = s;
        data = new int[s];
        for (size_t i = 0; i < size; i++) {
            data[i] = d[i];
        }
    }
    //Copy constructor
    //assignment operator=

    ~ArrayInt() {
        delete[] data;
    }

    void set_data(int* d, size_t length) {
        delete[] data;
        size = length;
        data = new int[length];
        memcpy(data, d, length * sizeof(int));
    }

    [[nodiscard]] int* get_data() const { return data; }
    [[nodiscard]] size_t get_size() const { return size; }

    int& operator[](size_t index) {
        if (index >= size) {
            throw "Incorrect index.";
        }
        return data[index];
    }

    const int& operator[](size_t index) const {
        if (index >= size) {
            throw "Incorrect index.";
        }
        return data[index];
    }
};

int main() {
    int ar[] = {1, 2, 3, 5};
    ArrayInt a(ar, 4);
    try {
        a[4] = 12;
        int b = a[-2];
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }


}
