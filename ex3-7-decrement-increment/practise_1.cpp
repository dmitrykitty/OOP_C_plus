#include <iostream>

class LimitLength {
    enum { min_length = -10, max_length = 10 };
    int length{0};
public:
    LimitLength(int len = 0) {
        if (len > max_length)
            length = max_length;
        else if (len < min_length)
            length = min_length;
        else
            length = len;
    }

    LimitLength& operator++() {
        if (length + 1 < max_length)
            ++length;
        return *this;
    }

    LimitLength operator++(int) {
        LimitLength tmp = *this;
        if (length + 1 < max_length)
            ++length;
        return tmp;
    }

    LimitLength& operator--() {
        if (length - 1 > min_length)
            --length;
        return *this;
    }

    LimitLength operator--(int) {
        LimitLength tmp = *this;
        if (length - 1 > min_length)
            --length;
        return tmp;
    }

    LimitLength& operator+=(int len) {
        if (length + len < max_length)
            length += len;
        else
            length = max_length;
        return *this;
    }

    LimitLength& operator-=(int len) {
        if (length - len > min_length)
            length -= len;
        else
            length = min_length;
        return *this;
    }

    LimitLength& operator*=(int len) {
        if (length * len > max_length)
            length = max_length;
        else if (length * len < min_length)
            length = min_length;
        else
            length *= len;

        return *this;
    }

    LimitLength& operator/=(int len) {
        if (length / len > max_length)
            length = max_length;
        else if (length / len < min_length)
            length = min_length;
        else
            length /= len;

        return *this;
    }

    operator int() const { return length; }

    int get_length() const { return length; }
};

int main() {
    return 0;
}
