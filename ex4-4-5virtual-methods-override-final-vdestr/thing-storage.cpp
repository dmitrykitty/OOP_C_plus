#include <iostream>
#include <string>

class Thing {
protected:
    std::string name;
    int price{0};

public:
    Thing(const std::string name = "", int price = 0) : name(name), price(price) {}

    virtual void print() {}
    const std::string &get_name() const { return name; }
    int get_price() const { return price; }
};

class Table : public Thing {
    int color{};
    double weight{};

public:
    Table(const std::string name, int price, int color, double weight) : Thing(name, price), color(color),
                                                                         weight(weight) {}

    void print() override {
        std::cout << "Table: " << name << ", " << price << ", " << color << ", " << weight << std::endl;
    }
};

class TV : public Thing {
    int size{};

public:
    TV(const std::string name, int price, int size) : Thing(name, price), size(size) {}

    void print() override {
        std::cout << "TV: " << name << ", " << price << ", " << size << std::endl;
    }
};

class Cart {
    enum { max_total_thing = 100 };

    Thing *goods[max_total_thing]{nullptr}; // товары в корзине
    int count{0}; // текущее количество товаров
public:
    void append(Thing *th) {
        if (count >= max_total_thing) return;
        goods[count++] = th;
    }

    Thing **get_goods() { return goods; }
    int get_count() const { return count; }

    void show() const {
        for (int i = 0; i < count; i++) {
            goods[i]->print();
        }
    }
};

int main() {
    Cart cart;
    cart.append(new Table("Oak", 12000, 0, 12.70));
    cart.append(new TV("Panasonic", 54000, 43));
    cart.append(new TV("Samsung", 83500, 54));
    cart.append(new Table("Old vintage", 9500, 432, 10.74));

    cart.show();

    for (int i = 0; i < cart.get_count(); i++) {
        if (cart.get_goods()[i] != nullptr) {
            delete cart.get_goods()[i];
            cart.get_goods()[i] = nullptr;
        }
    }

    return 0;
}
