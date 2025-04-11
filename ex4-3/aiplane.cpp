#include <iostream>

class Airplane {
protected:
    std::string model;
    unsigned max_speed{0};
    int length{0};

public:
    Airplane(std::string model, unsigned max_speed, int length): model(std::move(model)), max_speed(max_speed),
                                                                 length(length) {}

    const std::string &get_model() const { return model; }
    unsigned get_max_speed() const { return max_speed; }
    int get_length() const { return length; }
};

class MS21 : public Airplane {
    std::string drive_model;
    double weight{0.0};

public:
    MS21(std::string model, unsigned max_speed, int length, std::string drive_model,
         double weight): Airplane(std::move(model), max_speed, length), drive_model(std::move(drive_model)),
                         weight(weight) {}

    void get_info(std::string &drive_model, double &weight) const {
        drive_model = this->drive_model;
        weight = this->weight;
    }
};

int main() {
    MS21 ms21("MS 21", 1000, 212, "PD-14", 11.3);
    return 0;
}
