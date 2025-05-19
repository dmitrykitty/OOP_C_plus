#include <iostream>

class Clock {
    unsigned tm{};
public:
    Clock(unsigned time = 0) : tm(time) {}
    [[nodiscard]] unsigned get_time() const { return tm; }

    friend Clock operator+(const Clock& lhs, const Clock& rhs);

    Clock& operator+=(const Clock& rhs) {
        tm += rhs.tm;
        return *this;
    }

    Clock& operator-=(const Clock& rhs) {
        tm -= rhs.tm;
        return *this;
    }

    Clock& operator-=(const int rhs) {
        tm -= rhs;
        return *this;
    }

    Clock& operator+=(const int rhs) {
        tm += rhs;
        return *this;
    }

    Clock& operator++() {
        ++tm;
        return *this;
    }
    Clock operator++(int) {
        Clock tmp = *this;
        ++tm;
        return tmp;
    }
    Clock& operator--() {
        --tm;
        return *this;
    }

    Clock operator--(int) {
        Clock tmp = *this;
        --tm;
        return tmp;
    }

    operator unsigned() const { return tm; }

};

Clock operator+(const Clock& lhs, const Clock& rhs) {
    return {lhs.get_time() + rhs.get_time()};
}

int main() {
    Clock clock_1(100), clock_2(430);
    Clock res = clock_1 + clock_2;

}