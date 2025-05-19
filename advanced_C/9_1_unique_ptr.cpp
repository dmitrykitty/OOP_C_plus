#include<iostream>
#include <memory>

//smart pointers -> realizacja RAII dla dynamiocznie wydzielonej pamieci

template<typename T, typename Deleter = std::default_delete<T>>
class unique_ptr {
    T* ptr;
    [[no_unique_adress]]Deleter del; //custom deleter, nie jest obowiązkowy

public:
    explicit unique_ptr(T* ptr) : ptr(ptr) {}
    ~unique_ptr() {  del(ptr); }

    unique_ptr(const unique_ptr& x) = delete;

    unique_ptr& operator=(const unique_ptr& x) = delete;

    unique_ptr(unique_ptr&& other) noexcept: ptr(other.ptr), del(std::move(other.del)) {
        other.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            del(ptr);
            ptr = other.ptr;
            del = std::move(other.del);
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    T* get() const { return ptr; }
};


int main() {
    return 0;
}
