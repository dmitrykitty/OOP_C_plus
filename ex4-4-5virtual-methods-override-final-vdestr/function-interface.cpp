#include <iomanip>
#include <iostream>

class FunctionInterface {
public:
    virtual double func(double arg) { return 0; }
    virtual double operator()(double arg) { return 0; }
};

class LinearFunction : public FunctionInterface {
    double k{}, b{};

public:
    LinearFunction(double k_, double b_) : k{k_}, b{b_} {}
    double func(double arg) override { return k * arg + b; }
    double operator()(double arg) override { return k * arg + b; }
};

class ReluFunction : public FunctionInterface {
public:
    double func(double arg) override { return arg > 0 ? arg : 0; }
    double operator()(double arg) override { return arg > 0 ? arg : 0; }
};

int main() {
    FunctionInterface *funcs[3]{nullptr};
    funcs[0] = new LinearFunction(0.5, 0);
    funcs[1] = new LinearFunction(1.2, -5.4);
    funcs[2] = new ReluFunction();

    double x;
    std::cin >> x;
    std::cout << std::fixed << std::setprecision(2) << (*funcs[0])(x) << " " << (*funcs[1])(x) << " " << (*funcs[2])(x);

    delete funcs[0];
    delete funcs[1];
    delete funcs[2];
    return 0;
}
