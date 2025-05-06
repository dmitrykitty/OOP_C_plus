#include <exception>
#include <iostream>
#include <utility>

class VectorError : public std::exception {
protected:
    std::string msg;

public:
    VectorError(std::string error) noexcept : msg(std::move(error)) {}

    ~VectorError() override = default;

    [[nodiscard]] const char* what() const noexcept override { return msg.data(); }
};

class VectorErrorNegativeCoord : public VectorError {
    std::string msg;

public:
    explicit VectorErrorNegativeCoord(std::string error = "Negative coordinate value.") noexcept : VectorError(
        std::move(error)) {}
};

class Vector {
    int x{}, y{};

public:
    Vector() = default;

    Vector(int x, int y) {
        if (x < 0 || y < 0)
            throw VectorErrorNegativeCoord("Constructor: Negative coordinate value.");
        this->x = x;
        this->y = y;
    }

    [[nodiscard]] int get_x() const { return x; }
    [[nodiscard]] int get_y() const { return y; }

    void set_xy(int x, int y) {
        if (x < 0 || y < 0)
            throw VectorErrorNegativeCoord();
        this->x = x;
        this->y = y;
    }
};

int main() {
    int x{}, y{};
    std::cin >> x >> y;
    try {
        Vector vec(x, y);
        std::cout << vec.get_x() << " " << vec.get_y() << std::endl;
    } catch (const VectorError& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
