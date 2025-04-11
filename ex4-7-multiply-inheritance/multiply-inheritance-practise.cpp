#include <iterator>

class PhysicInterface {
public:
    virtual void forward(int speed) = 0; // движение вперед
    virtual void stop() = 0; // останов
    virtual void left(double angle) = 0; // поворот влево
    virtual void right(double angle) = 0; // поворот вправо

    virtual ~PhysicInterface() = default;
};

class Car {
protected:
    int speed{}, x{}, y{}, weight{};
    double angle{};

public:
    Car(int x, int y, int weight): x(x), y(y), weight(weight) {}

    void get_coords(int &x, int &y) const {
        x = this->x;
        y = this->y;
    }

    int get_speed() const { return speed; }
    int get_weight() const { return weight; }
    double get_angle() const { return angle; }

    virtual ~Car() = default;
};

class Train {
protected:
    int speed{}, x{}, y{}, weight{};
    double power{};

public:
    Train(int x, int y, int weight, double power): x(x), y(y), weight(weight), power(power) {}

    void get_coords(int &x, int &y) const {
        x = this->x;
        y = this->y;
    }

    int get_speed() const { return speed; }
    int get_weight() const { return weight; }
    double get_angle() const { return power; }

    virtual ~Train() = default;
};

class ModelCar : public PhysicInterface, public Car {
public:
    ModelCar(int x, int y, int weight): Car(x, y, weight) {}

    void forward(int speed) override { this->speed = speed; }
    void stop() override { speed = 0; }
    void left(double angle) override { this->angle = angle; }
    void right(double angle) override { this->angle = -1 * angle; }
};

class ModelTrain : public PhysicInterface, public Train {
public:
    ModelTrain(int x, int y, int weight, double power): Train(x, y, weight, power) {}

    void forward(int speed) override { this->speed = speed; }
    void stop() override { speed = 0; }
    void left(double angle) override {}
    void right(double angle) override {}
};

int main() {
    PhysicInterface *obj_lst[] = {
        new ModelCar(0, 0, 1200),
        new ModelTrain(-5, 7, 534200, 574.33),
        new ModelCar(11, 24, 1920),
        new ModelCar(-1, 12, 945)
    };

    for (auto &obj: obj_lst) {
        obj->forward(7);
    }

    for (auto &obj: obj_lst) {
        delete obj;
    }
}
