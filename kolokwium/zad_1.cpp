#include <algorithm>
#include <cstddef>
#include <utility>

class SmallVector {
    using T = int;
    static constexpr std::size_t N = 10;

    std::size_t size_ = 0;
    std::size_t capacity_ = N;
    T data1_[N]{};
    T* data2_ = nullptr;
    T* data() { return data2_ ? data2_ : data1_; }
    const T* data() const { return data2_ ? data2_ : data1_; }

public:

    class iterator {
        T* ptr_;
    public:
        iterator(T* p) : ptr_(p) {}

        iterator& operator++() {
            ++ptr_;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++ptr_;
            return tmp;
        }
        T& operator*() const {
            return *ptr_;
        }
        T* operator->() const {
            return ptr_;
        }
        bool operator==(const iterator& o) const {
            return ptr_ == o.ptr_;
        }
        bool operator!=(const iterator& o) const {
            return ptr_ != o.ptr_;
        }
    };

    SmallVector() = default;
    ~SmallVector() {
        delete[] data2_;
    }
    //COPY COSNTRUCTOR
    SmallVector(const SmallVector& o)
        : size_(o.size_), capacity_(o.capacity_) {
        if (o.data2_) {
            data2_ = new T[capacity_];
            std::copy(o.data2_, o.data2_ + size_, data2_);
        } else {
            std::copy(o.data1_, o.data1_ + size_, data1_);
        }
    }
    // MOVE COSNTRUCTOR
    SmallVector(SmallVector&& o) noexcept
        : size_(o.size_), capacity_(o.capacity_), data2_(o.data2_) {
        if (!o.data2_) {
            std::copy(o.data1_, o.data1_ + size_, data1_);
        }
        o.size_ = 0;
        o.capacity_ = N;
        o.data2_ = nullptr;
    }
    //COPY ASSIGNMENT
    SmallVector& operator=(const SmallVector& o) {
        if (this != &o) {
            delete[] data2_;
            size_ = o.size_;
            capacity_ = o.capacity_;
            if (o.data2_) {
                data2_ = new T[capacity_];
                std::copy(o.data2_, o.data2_ + size_, data2_);
            } else {
                data2_ = nullptr;
                std::copy(o.data1_, o.data1_ + size_, data1_);
            }
        }
        return *this;
    }
    //MOVE ASSIGNMENT
    SmallVector& operator=(SmallVector&& o) noexcept {
        if (this != &o) {
            delete[] data2_;
            size_ = o.size_;
            capacity_ = o.capacity_;
            data2_ = o.data2_;
            if (!data2_) {
                std::copy(o.data1_, o.data1_ + size_, data1_);
            }
            o.size_ = 0;
            o.capacity_ = N;
            o.data2_ = nullptr;
        }
        return *this;
    }
    iterator begin() { return iterator(data()); }
    iterator end() { return iterator(data() + size_); }

    void push_back(const T& v) {
        if (size_ == capacity_) {
            std::size_t newCap = capacity_ * 2;
            T* buf = new T[newCap];
            std::copy(data(), data() + size_, buf);
            delete[] data2_;
            data2_ = buf;
            capacity_ = newCap;
        }
        data()[size_++] = v;
    }
};
