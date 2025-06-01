#include <iostream>

int main() {
    bool (* func_filter[])(int) = {
        [](int a) { return a % 2 == 0; },
        [](int a) { return a < 0; },
        [](int a) { return a >= 0; }
    };

    int x;
    std::cin >> x;
    std::cout << func_filter[1](x);
}
