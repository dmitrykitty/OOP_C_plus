#include <string>

class Thing {
    unsigned id{0};

protected:
    std::string name;
    int price{};

public:
    Thing(std::string name = "", int price = 0) : name(std::move(name)), price(price) {}

    void set_data(const std::string &name, int price) {
        this->name = name;
        this->price = price;
    }

    unsigned get_id() const { return id; }
    std::string get_name() const { return name; }
    int get_price() const { return price; }
};

class ThingPhysical : public Thing {
    unsigned width{}, height{}, depth{};
    double weight{};

public:
    ThingPhysical(std::string _name = "", int price = 0,  int _width = 0, int _height = 0, int _depth = 0,
                  double _weight = 0.0): Thing(std::move(_name), price), width(_width), height(_height),
                                         depth(_depth), weight(_weight) {}

    void set_dims(unsigned width, unsigned height, unsigned depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }

    void set_weight(double weight) {
        this->weight = weight;
    }

    void get_dims(unsigned &width, unsigned &height, unsigned &depth) const {
        width = this->width;
        height = this->height;
        depth = this->depth;
    }

    double get_weight() const { return weight; }
};

class ThingElectro : public Thing {
    unsigned volume{};

public:
    explicit ThingElectro(std::string _name = "", int _price = 0, unsigned _volume = 0) : Thing(std::move(_name),
        _price), volume(_volume) {}

    void set_volume(unsigned volume) { this->volume = volume; }
    unsigned get_volume() const { return volume; }
};


int main() {
    return 0;
}
