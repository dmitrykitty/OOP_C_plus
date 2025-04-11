#include <iostream>
#include <utility>

class SmartPhone {
protected:
    std::string model;
    double weight{};

public:
    SmartPhone(std::string model, double weight) : model(std::move(model)), weight(weight) {}

    const std::string &get_model() const { return model; }
    double get_weight() const { return weight; }
};

class Iphone : public SmartPhone {
    int memory_volume{};
    int display_size{};

public:
    Iphone(std::string model, double weight, int memory_volume, int display_size): SmartPhone(std::move(model), weight),
        memory_volume(memory_volume), display_size(display_size) {}


    void get_info(int &memory_volume, int &display_size) const {
        memory_volume = this->memory_volume;
        display_size = this->display_size;
    }
};

int main() {
    Iphone iPhone12("iPhone12", 0.17, 64000, 11);

    return 0;
}
