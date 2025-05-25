#include <iostream>

enum ar_operation {
    ar_sum = 1,
    ar_sub = 2,
    ar_mul = 3
};

class Complex {
    int re{}, im{};

public:
    Complex(int r = 0, int i = 0): re(r), im(i) {}

    [[nodiscard]] int real() const { return re; }
    [[nodiscard]] int imag() const { return im; }

    void set_value(int real, int imag) {
        re = real;
        im = imag;
    }

    friend Complex operator+(const Complex& c1, const Complex& c2);

    friend Complex operator-(const Complex& c1, const Complex& c2);

    friend Complex operator*(const Complex& c1, const Complex& c2);
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return {c1.re + c2.re, c1.im + c2.im};
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return {c1.re - c2.re, c1.im - c2.im};
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return {c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c2.re * c1.im};
}

template<typename T>
T calc_data(T a, T b, ar_operation type = ar_sum) {
    switch (type) {
        case ar_sum:
            return a + b;
        case ar_sub:
            return a - b;
        default:
            return a * b;
    }
}


int main() {
    Complex cmp_1(-5, 23), cmp_2(14, 7);
    Complex res_1 = calc_data(cmp_1, cmp_2, ar_sub);
    double res_2 = calc_data(0.5, 10.4, ar_sum);
    int res_3 = calc_data(5, -11, ar_mul);
}
