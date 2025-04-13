#include <iostream>
#include <ostream>

class Object {
protected:
    int x{}, y{};
    int speed{};

public:
    Object(int x = 0, int y = 0, int speed = 0) : x(x), y(y), speed(speed) {}

    virtual ~Object() = default;

    void set_speed(int speed) { this->speed = speed; }
    int get_speed() const { return this->speed; }
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class ObjectFly : virtual public Object {
protected:
    int z{};
    double angle{};

public:
    ObjectFly(int z = 0, double angle = 0.0) : z(z), angle(angle) {}

    int get_z() const { return z; }
    double get_angle() const { return angle; }
    void set_angle(double angle) { this->angle = angle; }
};

class ObjectOperator : virtual public Object {
public:
    ObjectOperator(int x = 0, int y = 0, int speed = 0) : Object(x, y, speed) {}

    void operator+=(int delta) { speed += delta; }
    void operator-=(int delta) { speed -= delta; }
};

class Plane : public ObjectFly, public ObjectOperator {
public:
    Plane(int x = 0, int y = 0, int z = 0): Object(x, y), ObjectFly(z) {}
};

int main() {
    Plane plane(20, 43, 100);
    plane.set_speed(10);
    std::cout << plane.get_speed() << std::endl;
    plane += 5;

    std::cout << plane.get_speed() << std::endl;

    return 0;
}


