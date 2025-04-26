#include <iostream>

class Wallet {
    enum { wallet_limit = 1'000'000 };

    long volume{};

public:
    Wallet(long vol = 0) {
        if (vol > wallet_limit || vol < 0) {
            throw "Value is out of bounds.";
        }
        volume = vol;
    }

    [[nodiscard]] long get_volume() const { return volume; }

    Wallet& operator=(long money) {
        if (money > wallet_limit || money < 0) {
            throw "Volume is out of bounds.";
        }
        volume = money;
        return *this;
    }

    Wallet& operator+=(long money) {
        long new_volume = volume + money;
        if (new_volume > wallet_limit || new_volume < 0)
            throw "Volume is out of bounds.";
        volume = new_volume;
        return *this;
    }

    Wallet& operator-=(long money) {
        long new_volume = volume - money;
        if (new_volume > wallet_limit || new_volume < 0)
            throw "Volume is out of bounds.";
        volume = new_volume;
        return *this;
    }

    friend Wallet operator+(const Wallet& left, const Wallet& right);
};

Wallet operator+(const Wallet& left, const Wallet& right) {
    long new_volume = left.volume + right.volume;
    if (new_volume > Wallet::wallet_limit || new_volume < 0)
        throw "Volume is out of bounds.";
    return {new_volume};
}

int main() {
    try {
        Wallet wl(500);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}
