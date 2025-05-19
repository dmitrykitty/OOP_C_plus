#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using diff_func = double (*)(double);

class Diff {
    diff_func foo{};
    double dt{0.00001};

public:
    explicit Diff(diff_func f, double delta = 0.00001): foo(f), dt(delta) {}

    double operator()(double x) const {
        return (foo(x + dt) - foo(x))/dt;
    }
};

class Add {
    int add_value{};
public:
    explicit Add(int val): add_value(val){}

    void operator()(int& x) const {
        x += add_value;
    }

};

int main() {
    Diff diff_sin(sin);

    std::cout << diff_sin(M_PI / 2) << std::endl;

    std::vector<int> numbers{1, 2, 3};
    int n;
    std::cin >> n;
    Add addN(n);

    std::for_each(numbers.begin(), numbers.end(), addN);

    for (auto num : numbers)
        std::cout << num << std::endl;
}

