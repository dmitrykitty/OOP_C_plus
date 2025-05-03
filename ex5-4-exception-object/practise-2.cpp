#include <iostream>

class ExceptionConvert {
    std::string exception_text;

public:
    explicit ExceptionConvert(std::string ex) : exception_text(std::move(ex)) {}
    std::string& get_exception_text() { return exception_text; }
};

class ConvertToInt {
public:
    int operator()(const char* s) const {
        int i = 0;
        while (s[i] != '\0') {
            if (!std::isdigit(s[i]) && s[i] != '-' && s[i] != '+' && s[i] != '.')
                throw ExceptionConvert("Conversion error");
            i++;
        }

        try {
            return std::stoi(s);
        } catch (...) {
            throw ExceptionConvert("Conversion error");
        }
    }
};

int main() {
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str(); // массив символов char с прочитанной строкой

    ConvertToInt str_to_int;
    try {
        std::cout << str_to_int(str);
    } catch (ExceptionConvert& ex) {
        std::cout << ex.get_exception_text() << std::endl;
    }


    return 0;
}
