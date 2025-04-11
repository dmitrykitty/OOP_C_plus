#include <iostream>

class AbsoluteValue{
public:
    long value{0};
    AbsoluteValue(long value=0){
        this->value = value < 0 ? value * (-1) : value;
    }
    AbsoluteValue& operator=(long num){
        this->value = num < 0 ? num * (-1) : num;
        return *this;
    }
};

    int main()
    {
    auto* ptr_abv = new AbsoluteValue(-512);
    std::cout << ptr_abv->value << std::endl;

    *ptr_abv = -10;
    std::cout << ptr_abv->value << std::endl;
    delete ptr_abv;

    return 0;
    }