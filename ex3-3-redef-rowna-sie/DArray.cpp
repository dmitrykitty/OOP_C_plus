#include "DArray.h"

#include <shared_mutex>
#include <string.h>

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

DArray &DArray::operator=(DArray other) {
    swap(other);
    return *this;

    /*if (this == &other)
        return *this;

    length = other.length;
    capacity = other.capacity;

    delete[] data;
    data = new int[capacity];
    for (int i = 0; i < length; i++)
        data[i] = other.data[i];
    return *this;*/
}

DArray &DArray::operator+=(const DArray &other) {
    int length_new = length + other.length > max_length_array ? max_length_array : length + other.length;

    _resize_array(length_new);
    memcpy(data + length, other.data, sizeof(int) * other.length);
    length = length_new;
    return *this;
}

void DArray::swap(DArray &other) noexcept {
    std::swap(length, other.length);
    std::swap(capacity, other.capacity);
    std::swap(data, other.data);
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


int DArray::Item::operator=(int right) const {
    //zapisujemy nowe wartosic w data
    if (index < 0 || index >= max_length_array) //sprawdzamy poprawnosc indeksu
        return value_error;

    if (index >= current->capacity)
        current->_resize_array(index + 1); //zwiększamy wymiar jeżeli trzeba

    for (int i = current->length; i < index; i++)
        current->data[i] = 0; //zerukemy wszystko do indeksu


    if (index >= current->length) //zwiększamy capasity jezeli trzeba
        current->length = index + 1;

    current->data[index] = right;
    return right; //żeby działało a = b = c
}

int DArray::Item::_assign_operator(int right, type_assign type) const {
    if (!is_valid_index(index))
        return value_error;
    switch (type) {
        case add:
            current->data[index] += right;
            break;
        case sub:
            current->data[index] -= right;
            break;
        case mul:
            current->data[index] *= right;
            break;
        case div:
            current->data[index] /= right;
            break;
        case rem:
            current->data[index] %= right;
    }
    return current->data[index];
}

DArray::Item::operator int() const {
    //czytamy nowe wartosci z data
    return current->data[index];
}

int DArray::Item::operator+=(int right) const {
    return _assign_operator(right, add);
}

int DArray::Item::operator*=(int right) const {
    return _assign_operator(right, mul);
}

int DArray::Item::operator%=(int right) const {
    return _assign_operator(right, rem);
}

int DArray::Item::operator-=(int right) const {
    return _assign_operator(right, sub);
}

int DArray::Item::operator/=(int right) const {
    return _assign_operator(right, div);
}

int DArray::Item::operator++() const {
    if (!is_valid_index(index))
        return value_error;
    return ++current->data[index];
}

int DArray::Item::operator++(int) const {
    if (!is_valid_index(index))
        return value_error;
    return current->data[index]++;
}
