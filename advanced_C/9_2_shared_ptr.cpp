#include <memory>

template<typename T>
class shared_ptr {
    T* ptr;

    //dlaczego nie zadziała int count?
    //static int count - wspolny count dla wszystkich T, dla jednego typu moze byc static

    int* count;
    shared_ptr(T* ptr): ptr(ptr), count(new int(1)) {}

    shared_ptr(const shared_ptr& other): ptr(other.ptr), count(other.count) {
        ++*count;
    }

    ~shared_ptr() {
        if (!count) {
            return;
        }
        --*count;
        if (!*count) {
            delete count;
            delete ptr;
        }
    }
};


int main() {
    auto p = std::shared_ptr<int>(new int(1));

    auto p2 = p;
    auto p3 = p;

    p2.reset(new int(7));
    auto p4 = std::move(p); //p -> nullptr
}
