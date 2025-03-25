#include <iostream>

class Array {
    double *data{nullptr};
    size_t size{0};

    explicit Array(size_t size): size(size)
    {
        data = new double[size]{0};
    }

    Array(const double *data, size_t size): Array(size)
    {
        for (size_t i = 0; i < this->size && i < size; i++)
            this->data[i] = data[i];
    }

public:
    static Array *create(size_t size)
    {
        Array *ar = new Array(size);
        return ar;
    }

    static Array *create(const double *data, size_t size)
    {
        Array *ar = new Array(data, size);
        return ar;
    }

    void set_data(double *d, size_t length)
    {
        delete[] data;
        size = length;
        data = new double[size];

        for (size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    double *get_data() { return data; }
    size_t get_size() { return size; }

    ~Array()
    {
        delete[] data;
    }
};

int main()
{
    size_t total = 100;
    Array *ar1 = Array::create(total);

    double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    Array *ar2 = Array::create(d, sizeof(d) / sizeof(*d));

    delete ar1;
    delete ar2;


    return 0;
}
