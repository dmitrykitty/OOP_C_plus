#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    short old{0};
};

class Cat : public Animal {
    int color{};
    double weight{};

public:
    Cat(std::string &&name, short &&old, int &&color, double &&weight) {
        this->name = name;
        this->old = old;
        this->color = color;
        this->weight = weight;
    }

    void get_data(std::string &name, short &old, int &color, double &weight) const {
        name = this->name;
        old = this->old;
        color = this->color;
        weight = this->weight;
    }
};

class Dog : public Animal {
    int height{}, speed{};

public:
    Dog(std::string &&name, short &&old, int &&height, int &&speed) {
        this->name = name;
        this->old = old;
        this->height = height;
        this->speed = speed;
    }

    void get_data(std::string &name, short &old, int &height, int &speed) const {
        name = this->name;
        old = this->old;
        height = this->height;
        speed = this->speed;
    }
};

int main() {
    Cat cat_1("Zeus", 5, 0, 1.2);
    Cat cat_2("Poseidon", 7, 122, 0.9);

    Dog dog_1("Rex", 10, 50, 32);

}
