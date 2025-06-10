#include <compare>
#include <iostream>
#include <vector>
//moze byc inregral ypes + od C++ 20 float, double
//ale nie mozna przekazywac wtedy zmienne, dopoki ta zmiena nie jest constexpr

template<typename T, size_t N>
class array {
    T arr[N];
};

template<size_t M, size_t N, typename T = double>
class Matrix {
    std::vector<std::vector<T> > data;
    Matrix(): data(M, std::vector<T>(N)) {}
};

template<size_t N, typename T = double>
using SquareMatrix = Matrix<N, N, T>;

template<size_t M, size_t K, size_t N, typename T>
Matrix<M, N, T> operator*(const Matrix<M, K, T>& a, const Matrix<K, N, T>& b);

//Template template params
template<typename T, template<typename> class Container = std::vector>
class Stack {
    Container<T> cont; //czyli Stack jest obudową nad template class, gdzie jako default jest std::vector
};

int main() {
    Stack<int, std::vector> s;
    Stack<int> d; //działa też, xD
}
