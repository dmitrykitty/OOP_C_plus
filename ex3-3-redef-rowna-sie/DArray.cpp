#include "DArray.h"

void DArray::_resize_array(int size_new) {
    if (size_new <= capacity)
        return;
    while (size_new > capacity) {
        capacity *= resize_factor;
        if (capacity >= max_length_array) {
            capacity = max_length_array;
            break;
        }
    }
    int *temp = new int[capacity];
    for (int i = 0; i < length; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

DArray &DArray::operator=(const DArray &other) {
    if (this == &other)
        return *this;

    length = other.length;
    capacity = other.capacity;

    delete[] data;
    data = new int[capacity];
    for (int i = 0; i < length; i++)
        data[i] = other.data[i];
    return *this;
}

void DArray::push_back(const int &value) {
    if (length >= capacity) {
        _resize_array(capacity * resize_factor);
    }
    if (length < capacity) {
        data[length++] = value;
    }
}

int DArray::pop_back() {
    if (length == 0)
        return value_error;
    return data[--length];
}
