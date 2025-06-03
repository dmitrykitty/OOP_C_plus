#include <functional>
#include <map>

template<typename T>
T sq_rect(T a, T b) {
    return a * b;
}


template<typename T>
class vector {
    T* arr_;
    size_t sz_;
    size_t capacity_;
};

template<typename T>
struct less {
    bool operator()(const T& x, const T& y) const {
        return x < y;
    }
};

//using template
template<typename T>
using mymap = std::map<T, T, std::greater<T> >; //greater - comporator

//teraz mymap<int> ozancza to, co by napisane wyzej
mymap<int> m;

int main() {
    sq_rect(1, 2); //ok
    sq_rect(1, 2L); //błąd, rozne typy
    sq_rect<long>(1, 2L); //ok
    //kod dla template jest generowany na samym początku(template generation) i jak są rozne pary T
    //będą to zupełnie inne funkcje
}
