#include<iostream>
#include <utility>

class Equipment {
    inline static unsigned long uid{};

protected:
    bool is_exists{false};

public:
    Equipment(bool a = false): is_exists(a) { uid++; }

    static unsigned long get_uid() { return uid; }
    virtual void print() const {}

    virtual ~Equipment() = default;
};

class PC: public Equipment {
    std::string model;
    int price{};
public:
    PC(std::string model, int price, bool is_exists): Equipment(is_exists), model(std::move(model)), price(price) {}
    std::string get_model() const { return model; }
    int get_price() const { return price; }
    void print() const override {
        std::cout << "PC: " << model << ", " << price << "," << is_exists << std::endl;
    }

    ~PC() override { std::cout << "~PC" << std::endl;}
};


int main() {

    Equipment* pc = new PC("Lenovo", 3445643, true);
    pc->print();

    Equipment r(false);

    std::cout << pc->get_uid() << std::endl;

    delete pc;

    return 0;
}