#include <iostream>
#include <cmath>
#include <algorithm>

template<typename T>
void ar_sort(T* ar, size_t len, bool (* compare)(T a, T b)) {
    std::sort(ar, ar + len, compare);
}

int main() {
    int data[] = {5, -3, 10, 0, 33, 7, -12};
    ar_sort<int>(data, std::size(data),
                 [](int a, int b) { return abs(a) < abs(b); });

    for (const int& i : data)
        std::cout << i << " ";
    return 0;
}
