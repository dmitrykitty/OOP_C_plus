#include <iostream>
#include <exception>

class LengthValueError : public std::exception {
    std::string msg;

public:
    explicit LengthValueError(const char* txt): msg(txt) {}

    LengthValueError(const LengthValueError&) = default;

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template<typename T = short>
class Triangle {
    T a{0}, b{0}, c{0};

public:
    Triangle() = default;

    Triangle(T a, T b, T c) {
        set_abc(a, b, c);
    }

    void get_abc(T& a, T& b, T& c) const {
        a = this->a;
        b = this->b;
        c = this->c;
    }

    void set_abc(T a, T b, T c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw LengthValueError("Length must be a positive number.");
        this->a = a;
        this->b = b;
        this->c = c;
    }
};


int main() {
    try {
        Triangle tr(7, -4, 10);
    } catch (const LengthValueError& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
