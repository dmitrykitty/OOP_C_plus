#include <iostream>


class TimeValue {
protected:
    unsigned tm{0}; // текущее время
public:
    unsigned get_time() const { return tm; }

    virtual ~TimeValue() = default;
};

class ClockOperators : virtual public TimeValue {
public:
    ClockOperators(unsigned tm) { this->tm = tm; }

    unsigned operator+(const ClockOperators &right) const {
        return this->tm + right.tm;
    }

    ~ClockOperators() override = default;
};

class ClockPrint : virtual public TimeValue {
public:
    void print() const {
        unsigned h = tm / 3600;
        unsigned m = (tm - h * 3600) / 60;
        unsigned s = (tm - h * 3600 - m * 60);

        printf("%02u:%02u:%02u\n", h, m, s);
    }

    ~ClockPrint() override = default;
};

class Clock : public ClockOperators, public ClockPrint {
public:
    Clock(unsigned tm = 0): ClockOperators(tm) {}

    static void delete_m(Clock *cl) {
        delete cl;
    }
};

int main() {
    Clock cl_1(15334), cl_2(43654);
    Clock res = cl_1 + cl_2;
    res.print();
    std::cout << res.get_time() << std::endl;




    auto *cl = new Clock(3546);
    int *a = new int;

    delete a;
    Clock::delete_m(cl);

    return 0;
}
