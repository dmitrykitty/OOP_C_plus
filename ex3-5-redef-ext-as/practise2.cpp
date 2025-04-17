#include <string>
#include <utility>

class BankAccount {
    std::string fio;
    long volume_rub{};

public:
    BankAccount(std::string fio, long volume_rub = 0): fio(std::move(fio)), volume_rub(volume_rub) {}

    const std::string &get_fio() const { return fio; }
    long get_volume() const { return volume_rub; }

    BankAccount& operator=(long right) {
        volume_rub = right;
        return *this;
    }

    BankAccount &operator+=(const BankAccount &right) {
        volume_rub += right.volume_rub;
        return *this;
    }

    BankAccount &operator-=(const BankAccount &right) {
        volume_rub -= right.volume_rub;
        return *this;
    }

    BankAccount &operator+=(long right) {
        volume_rub += right;
        return *this;
    }

    BankAccount &operator-=(long right) {
        volume_rub -= right;
        return *this;
    }
};
