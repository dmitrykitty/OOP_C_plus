#include <iostream>
#include <iomanip>

class Distance{
    long dist{0};
public:
    Distance(long int d=0): dist(d){}
    friend void set_distance(Distance& dst, long value); // заносит в поле dist объекта dst значение value
    friend long get_distance(const Distance& dst); // возвращает значение поля dist объекта dst
    friend double distance_to_meters(const Distance& dst); // возвращает значение поля dist объекта dst в метрах
    friend Distance operator+(const Distance& left, const Distance& right);
};
void set_distance(Distance& dst, long value){ dst.dist = value; }
long get_distance(const Distance& dst){ return dst.dist; }
double distance_to_meters(const Distance& dst){ return (double)dst.dist / (double)1000; }
Distance operator+(const Distance& left, const Distance& right){ return left.dist + right.dist; }

int main(void)
{
    Distance d(783);
    std::cout << get_distance(d) << " " << std::fixed << std::setprecision(3) << distance_to_meters(d);


    return 0;
}