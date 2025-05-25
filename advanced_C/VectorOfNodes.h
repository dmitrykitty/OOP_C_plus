#ifndef VECTOROFNODES_H
#define VECTOROFNODES_H
#include <cstdint>
#include <list>
#include <string>
#include <compare>
#include <iostream>

class VectorOfNodes {
    //------------------------------NODE---------------------------------
    struct Node {
        std::list<std::string> strList;
        uint64_t hash;
    };

    //------------------------------PRIVATE_FIELDS---------------------------------
    Node* arr_ = nullptr;
    size_t sz_{};
    size_t capacity_{};

    //------------------------------METODY_POMOCNICZE---------------------------------

protected:
    void copy(const VectorOfNodes& other);
    void move(VectorOfNodes&& other);
    void free();
    void swap(VectorOfNodes& other);

public:
    //------------------------------ITERATOR---------------------------------
    class iterator {
    public:
        using difference_type = std::ptrdiff_t;
    private:

        Node* ptr{};

    public:
        iterator() = default;
        iterator(Node* nodePtr): ptr(nodePtr) {}
        iterator(const iterator& other) = default;

        Node& operator*() const { return *ptr; }
        Node* operator->() const { return ptr; }

        iterator& operator++() {
            ++ptr;
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            ++ptr;
            return temp;
        }
        //to samo dla --
        bool operator==(const iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        std::strong_ordering operator<=>(const iterator& other) const { return ptr <=> other.ptr; }

        //to samo dla - oraz -=
        iterator operator+(const difference_type n){ return {ptr + n}; }
        iterator& operator+=(const difference_type n){ ptr += n; return *this; }
        difference_type operator-(const iterator& other) const { return ptr - other.ptr; }
    };

    iterator begin() { return {arr_}; }
    iterator end() { return {arr_ + sz_}; }

    //------------------------------CSTR, DSTR---------------------------------
    VectorOfNodes(size_t size);
    VectorOfNodes(const VectorOfNodes& other);
    VectorOfNodes(VectorOfNodes&& other);
    ~VectorOfNodes();

    //------------------------------OPERATORS---------------------------------
    VectorOfNodes& operator=(VectorOfNodes other);

    void push_back(const Node& newNode);
    void reserve(size_t newCapacity);
};


#endif //VECTOROFNODES_H
