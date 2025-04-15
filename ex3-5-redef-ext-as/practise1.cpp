#include <iostream>

class BottleWater {
    enum { max_volume = 640 }; // максимальный объем воды
    short volume{}; // объем воды в бутылке
public:
    BottleWater(short volume = 0) : volume(volume) {}

    BottleWater operator+(const BottleWater &other) const {
        short total = volume + other.volume;
        return total  > max_volume ? max_volume : total;
    }
    

    short get_volume() const { return volume; }
};

int main() {
    // здесь продолжайте функцию main

    return 0;
}
