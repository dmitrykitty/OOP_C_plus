#include <iostream>

class BottleWater {
    enum type_assign {
        add, sub, mul, div, rem
    };

    enum { max_volume = 640 }; // максимальный объем воды
    short volume{}; // объем воды в бутылке
public:
    BottleWater(short volume = 0) : volume(volume) {}

    BottleWater operator+(const BottleWater &other) const {
        int total = volume + other.volume;
        return total > max_volume ? max_volume : static_cast<short>(total);
    }

    short get_volume() const { return volume; }

    int _assign_operator(const BottleWater &right, type_assign type) {
        switch (type) {
            case add:
                volume += right.volume;
                break;
            case sub:
                volume -= right.volume;
                break;
            case mul:
                volume *= right.volume;
                break;
            default:
                volume /= right.volume;
        }
        if (volume > max_volume)
            volume = max_volume;
        else if (volume < 0)
            volume = 0;
        return volume;
    }

    int operator+=(const BottleWater &right) {
        return _assign_operator(right, add);
    }
    int operator*=(const BottleWater &right) {
        return _assign_operator(right, mul);
    }
    int operator/=(const BottleWater &right) {
        return _assign_operator(right, div);
    }
    int operator-=(const BottleWater &right) {
        return _assign_operator(right, sub);
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    BottleWater bw1(40), bw2(200);
    BottleWater res = bw1 + bw2;
    std::cout << res.get_volume() << std::endl;
    bw1 -= bw2;
    std::cout << bw1.get_volume() << std::endl;
    bw1 += 150;
    std::cout << bw1.get_volume() << std::endl;
    bw1 -= 140;
    std::cout << bw1.get_volume() << std::endl;
    bw1 /= 2;
    std::cout << bw1.get_volume() << std::endl;

    return 0;
}
