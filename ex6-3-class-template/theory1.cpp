template<typename T = short>
struct Point {
    T x{}, y{};
    Point(const T& x, const T& y): x(x), y(y) {}

    T diff();
};

//realicja metody poza klasem
template<typename T>
T Point<T>::diff() {
    return x - y;
}

template<typename T1, typename T2>
struct B {
    T1 x{};
    T2 y{};
    inline static T1 counter = 0;
    static T2 c2;
    B(T1 x, T2 y);

    T1 get_x() const { return x; }
};

//realizacja konstruktora poza klasem
template<typename T1, typename T2>
B<T1, T2>::B(T1 x, T2 y): x(x), y(y){}

template<typename T1, typename T2>
T2 B<T1, T2>::c2 = 0;


int main() {
    Point<int> pt1(5, 3);
    Point<double> pt2(5, 3);
    Point pt3(1, 3);
    //Point pt4(1, 4.5); //bład
    Point<double> pt5(1, 3.8); //ok

    B b(1, 5.5); //ok, bo 2 parametry

    return 0;
}
