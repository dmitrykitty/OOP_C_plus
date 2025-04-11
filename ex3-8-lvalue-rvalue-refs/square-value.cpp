#include <iostream>
#include <string>

class SquareValue{
    unsigned value{0};
public:
    SquareValue(int _value=0): value{static_cast<unsigned int>(_value * _value)} { }

    SquareValue& operator=(const int& num){
        value = static_cast<unsigned int>(num * num);
        return *this;
    }
    operator unsigned() const { return value; }
};

int main()
{
    SquareValue sq(7);
    SquareValue& lnk_sq = sq;
    SquareValue&& lnk_r_sq = std::move(sq);


    return 0;
}