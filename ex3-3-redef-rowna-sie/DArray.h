#ifndef DARRAY_H
#define DARRAY_H


class DArray {
    enum {
        start_length_array = 8,
        resize_factor = 2,
        max_length_array = 64,
        value_error = 2123456789
    };

    int *data{nullptr};
    int length{0};
    int capacity{0};

    void _resize_array(int size_new);

public:
    DArray(): capacity{start_length_array} {
        data = new int[capacity];
    }

    DArray(const DArray &other): length{other.length}, capacity{other.capacity} {
        data = new int[capacity];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    ~DArray() { delete[] data; }

    int
    get_size() const { return length; }

    int
    get_capacity() const { return capacity; }

    const int *
    get_data() const { return data; }

    DArray &operator=(const DArray &other);

    void push_back(const int &value);

    int pop_back();
};


#endif //DARRAY_H
