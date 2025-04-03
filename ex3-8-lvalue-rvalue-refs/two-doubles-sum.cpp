#include <iostream>

class ValueDouble {
    double value{0.0};

public:
    ValueDouble(double _value = 0.0): value(_value) {}

    double get_value() const { return value; }

    friend ValueDouble operator+(const ValueDouble &left, const ValueDouble &right);
};

ValueDouble operator+(const ValueDouble &left, const ValueDouble &right) {
    return {left.value + right.value};
}


int main() {
    ValueDouble num = ValueDouble(8.7);
    ValueDouble &lnum = num;
    ValueDouble &&rnum = std::move(num);

    ValueDouble *num2 = new ValueDouble(5.4);
    ValueDouble &lnum2 = *num2;
    ValueDouble &&rnum2 = std::move(*num2);

    ValueDouble sum = num + *num2;
    ValueDouble &&rsum = lnum + lnum2;

    std::cout << sum.get_value() << " " << rsum.get_value() << std::endl;

    delete num2;
    return 0;
}
