#include <iostream>

template<typename T>
T ar_sum(const T* ar, size_t n, bool (* func)(T)) {
    T sum = 0;
    for (size_t i = 0; i < n; ++i) {
        if (func(ar[i]))
            sum += ar[i];
    }
    return sum;
}

int main() {
    double data[] = {-1, 2.5, -3, -4, 5.1, 6};
    auto res = ar_sum<double>(data, std::size(data),
                              [](double a) { return a > 0; });
    //kompilator nie moze srzutowac labde do bool (*) (double), wiec trzeba jawnie wskazac typ double
    std::cout << res;


    return 0;
}
