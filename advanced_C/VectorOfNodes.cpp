#include <new>
#include "VectorOfNodes.h"
//------------------------------METODY_POMOCNICZE---------------------------------

void VectorOfNodes::copy(const VectorOfNodes& other) {
    arr_ = static_cast<Node *>(::operator new[](other.capacity_ * sizeof(Node)));
    for (size_t i = 0; i < other.sz_; ++i)
        new(arr_ + i)Node(std::move(other.arr_[i]));

    sz_ = other.sz_;
    capacity_ = other.capacity_;
}

void VectorOfNodes::move(VectorOfNodes&& other) noexcept {
    arr_ = other.arr_;
    sz_ = other.sz_;
    capacity_ = other.capacity_;

    other.sz_ = other.capacity_ = 0;
    other.arr_ = nullptr;
}

void VectorOfNodes::free() {
    for (std::size_t i = 0; i < sz_; ++i)
        arr_[i].~Node();
    ::operator delete[](arr_);

    arr_ = nullptr;
    sz_ = capacity_ = 0;
}

void VectorOfNodes::swap(VectorOfNodes& other) {
    std::swap(sz_, other.sz_);
    std::swap(capacity_, other.capacity_);
    std::swap(arr_, other.arr_);
}

//------------------------------KONSTRUKTORY---------------------------------
VectorOfNodes::VectorOfNodes(size_t size = 0) {
    if (size) {
        reserve(size);
        for (size_t i = 0; i < sz_; ++i) {
            new(arr_ + i)Node(); //placement new
        }
        sz_ = size;
    }
}

VectorOfNodes::VectorOfNodes(const VectorOfNodes& other) {
    copy(other);
}

VectorOfNodes::VectorOfNodes(VectorOfNodes&& other) noexcept {
    move(std::move(other)); //rzutowanie do r-value
}

//------------------------------DESTRUKTOR---------------------------------
VectorOfNodes::~VectorOfNodes() {
    free();
}

//------------------------------OPERATORS---------------------------------

VectorOfNodes& VectorOfNodes::operator=(VectorOfNodes other) {
    //dla r_value - move cstr, dla l-value copy cstr
    swap(other);
    return *this;
}

VectorOfNodes::Node& VectorOfNodes::operator[](size_t index) {
    return arr_[index];
}

const VectorOfNodes::Node& VectorOfNodes::operator[](size_t index) const {
    return arr_[index];
}

//------------------------------RESERVE---------------------------------
void VectorOfNodes::reserve(size_t newCapacity) {
    if (capacity_ >= newCapacity)
        return;

    Node* newArr = static_cast<Node *>(::operator new[](newCapacity * sizeof(Node)));
    //wydzielenie surowej pamieci
    for (size_t i = 0; i < sz_; ++i)
        new(newArr + i)Node(std::move(arr_[i]));


    for (size_t i = 0; i < sz_; ++i)
        arr_[i].~Node();
    ::operator delete [](arr_);

    capacity_ = newCapacity;
    arr_ = newArr;
}

//------------------------------PUSH_BACK---------------------------------
void VectorOfNodes::push_back(const Node& newNode) {
    if (sz_ == capacity_)
        reserve(capacity_ ? capacity_ * 2 : 1);

    new(arr_ + sz_)Node(newNode);
    ++sz_;
}

//------------------------------POP_BACK---------------------------------
void VectorOfNodes::pop_back() {
    if (back()) {
        back().~Node();
        --sz_;
    }
}

//------------------------------AT---------------------------------
VectorOfNodes::Node& VectorOfNodes::at(size_t index) {
    if (index >= sz_)
        throw std::out_of_range("VectorOfNodes::at");
    return arr_[index];
}

const VectorOfNodes::Node& VectorOfNodes::at(size_t index) const {
    if (index >= sz_)
        throw std::out_of_range("VectorOfNodes::at");
    return arr_[index];
}

//------------------------------SHRINK_TO_FIT---------------------------------

void VectorOfNodes::shrink_to_fit() {
    if (capacity_ == sz_)
        return;

    if (sz_ == 0) {
        free();
        return;
    }
    Node* newArr = static_cast<Node *>(::operator new [](sz_ * sizeof(Node)));

    for (size_t i = 0; i < sz_; ++i)
        new(newArr + i)Node(std::move(arr_[i]));
    for (size_t i = 0; i < sz_; ++i)
        arr_[i].~Node();

    ::operator delete [](arr_);
    arr_ = newArr;
    capacity_ = sz_;
}

//------------------------------INSERT---------------------------------

VectorOfNodes::iterator VectorOfNodes::insert(iterator pos, const Node& value) {
    size_t index = pos - begin();
    if (sz_ == capacity_)
        reserve(capacity_ ? capacity_ * 2 : 1);
    new(arr_ + sz_)Node(std::move(arr_[sz_ - 1]));
    for (size_t i = sz_ - 1; i > index; ++i)
        arr_[i] = std::move(arr_[i - 1]);

    arr_[index].~Node();
    new(arr_ + index)Node(value);
    ++sz_;
    return {arr_ + index};
}
