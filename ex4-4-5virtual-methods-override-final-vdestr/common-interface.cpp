#include <iostream>
#include <string>

class CommonInterface {
public:
    virtual ~CommonInterface() = default;

    virtual long long get_id() const = 0;

    virtual void set_id(long long id) = 0;
};

class Thing : public CommonInterface {
    long long id{};
    std::string name;
    int price{};

public:
    Thing(long long id, std::string name, int price) : id(id), name(std::move(name)), price(price) {}

    long long get_id() const override { return id; }
    void set_id(long long id) override { this->id = id; }
    const std::string &get_name() const { return name; }
    int get_price() const { return price; }
};

enum { max_size = 100, size = 4 };

int main() {
    CommonInterface *lst[max_size] = {
        new Thing(4, "Book C++", 2500),
        new Thing(1, "Computer HP", 125000),
        new Thing(10, "Mouse Lg", 4300),
        new Thing(19, "Monitor Samsung", 9560),
    };

    for (int i = 0; i < size; ++i)
        std::cout << lst[i]->get_id() << " ";

    for (int i = 0; i < size; ++i) {
        delete lst[i];
        lst[i] = nullptr;
    }
    return 0;
}
