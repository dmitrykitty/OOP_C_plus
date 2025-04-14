#include "DArray.h"

#include <shared_mutex>

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

void DArray::swap(DArray& other) noexcept {
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


int DArray::Item::operator=(int right) const { //zapisujemy nowe wartosic w data
    if (index < 0 || index >= max_length_array) //sprawdzamy poprawnosc indeksu
        return value_error;

    if (index >= current->capacity)
        current->_resize_array(index + 1); //zwiększamy wymiar jeżeli trzeba

    for (int i = current->length; i < index; i++)
        current->data[i] = 0;//zerukemy wszystko do indeksu


    if (index >= current->length) //zwiększamy capasity jezeli trzeba
        current->length = index + 1;

    current->data[index] = right;
    return right; //żeby działało a = b = c

}
DArray::Item::operator int() const {//czytamy nowe wartosci z data
    if (index < 0 || index >= current->length)
        return value_error;
    return current->data[index];

}
