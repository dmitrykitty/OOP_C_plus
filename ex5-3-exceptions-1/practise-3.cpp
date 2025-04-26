#include <iostream>

class Validator {
protected:
    std::string msg_ex;

public:
    Validator(std::string msg_ex) : msg_ex(std::move(msg_ex)) {}

    virtual bool is_valid(int x, bool exception = true) const = 0;

    virtual ~Validator() = default;
};

class ValidatorRange : public Validator {
    int min_value{}, max_value{};

public:
    ValidatorRange(const std::string& msg, int min, int max): Validator(msg), min_value(min), max_value(max) {}

    [[nodiscard]] bool is_valid(int x, bool exception = true) const override {
        if (!exception)
            return x >= min_value && x <= max_value;

        if (x < min_value || x > max_value)
            throw msg_ex;

        return true;
    }
};

int main() {
    ValidatorRange vr("Value is outside the range [0; 15]", 0, 15);
    int x;

    std::cin >> x;
    try {
        bool res = vr.is_valid(x);
    } catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}
