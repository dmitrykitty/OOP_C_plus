class Line {
    short x0{}, y0{}, x1{}, y1{};
    int color{};

public:
    Line() = default;
    Line(short x0, short y0, short x1, short y1): x0(x0), y0(y0), x1(x1), y1(y1) {}
    int get_color() const { return color; }

    void get_coords(short &x0, short &y0, short &x1, short &y1) const {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }

    void set_coords(short x0, short y0, short x1, short y1) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }

    void set_color(int color) { this->color = color; }

    Line& operator=(const Line &right) {
        x0 = right.x0;
        y0 = right.y0;
        x1 = right.x1;
        y1 = right.y1;
        return *this;
    }

    Line& operator+=(const Line &right) {
        x0 += right.x0;
        y0 += right.y0;
        x1 += right.x1;
        y1 += right.y1;
        return *this;
    }

    Line& operator-=(const Line &right) {
        x0 -= right.x0;
        y0 -= right.y0;
        x1 -= right.x1;
        y1 -= right.y1;
        return *this;
    }

    friend Line operator+(const Line &left, const Line &right);
};

Line operator+(const Line &left, const Line &right) {
    Line res = left;
    res += right;
    return res;
}
