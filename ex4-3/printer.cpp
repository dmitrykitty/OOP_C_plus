#include <iostream>

class Printer {
public:
    enum type_printer {
        pr_none = 0,
        pr_needle = 1,
        pr_jet = 2,
        pr_laser = 3
    };

private:
    std::string model;
    type_printer type{pr_none};

public:
    Printer(std::string model, type_printer type) :     model(std::move(model)), type(type) {}

    const std::string &get_model() const { return model; }
    type_printer get_type() const { return type; }
};

class PrinterJet : public Printer {
    bool color{false};
    short speed{0};

public:
    PrinterJet(std::string model, bool color, short speed) : Printer(std::move(model), pr_jet), color(color),
                                                             speed(speed) {}


    void get_data(std::string &model, type_printer &type, bool &color, short &speed) const {
        model = this->get_model();
        type = this->get_type();
        color = this->color;
        speed = this->speed;
    }
};

class PrinterLaser : public Printer {
    bool color{false};
    short speed{0};

public:
    PrinterLaser(std::string model, bool color, short speed) : Printer(std::move(model), pr_laser), color(color),
                                                               speed(speed) {}


    void get_data(std::string &model, type_printer &type, bool &color, short &speed) const {
        model = this->get_model();
        type = this->get_type();
        color = this->color;
        speed = this->speed;
    }
};

int main() {
    Printer *pr_lst[] = {
        new PrinterJet("Brother Jet 600", true, 5),
        new PrinterLaser("Canon Laser 10", false, 10),
        new PrinterJet("Samsung Jet 100", true, 7),
        new PrinterLaser("BaLaser 1 Pro", true, 21)
    };

    for (auto & i : pr_lst) {
        delete i;
    }

    return 0;
}
