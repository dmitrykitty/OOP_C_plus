#include <iostream>

template<typename T>
struct Point {
    T x{}, y{};

    Point() = default;

    Point(T x, T y): x(x), y(y) {}
};

template<typename D>
class Line {
    Point<D> sp, ep;

public:
    Line() = default;

    Line(const Point<D>& start, const Point<D>& end) {
        set_coords(start, end);
    }

    Line(D x0, D x1, D y0, D y1): Line(Point<D>(x0, y0), Point<D>(x1, y1)) {}
    Point<D> get_sp() const { return sp; }
    Point<D> get_ep() const { return ep; }

    void set_coords(const Point<D>& start, const Point<D>& end) {
        sp = start;
        ep = end;
    }
};

int main() {
    Line<unsigned> line(Point<unsigned>(1, 2), Point<unsigned>(11, 54));
}
