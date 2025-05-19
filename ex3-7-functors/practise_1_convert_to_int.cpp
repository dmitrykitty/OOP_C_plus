#include <iostream>
#include <cstring>

class ConvertToInt {
    bool is_not_converted{false};
public:
    int operator()(const char* str) {
        for (int i = 0; i < strlen(str); ++i) {
            if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-' && str[i] != '.')) {
                is_not_converted = true;
                return 0;
            }
        }
        is_not_converted = false;
        return std::stoi(str);
    }

    [[nodiscard]]bool is_error() const { return is_not_converted; }
};

int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str();
    ConvertToInt str_to_int;
    std::cout << str_to_int(str) << " " << str_to_int.is_error() << std::endl;

    return 0;
}