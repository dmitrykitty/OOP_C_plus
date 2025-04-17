#include <algorithm>
#include <iostream>
#include <string>

struct BankAccount {
    enum type_assign {
        add, sub, mul, div, rem
    };

    std::string fio;
    long volume{0};

    BankAccount() = default;

    BankAccount(const std::string &fio, long vol) : fio(fio), volume(vol) {}

    BankAccount &operator+=(long right) {
        return _assign_operator(right, add);
    }

    BankAccount &operator-=(long right) {
        return _assign_operator(right, sub);
    }

    BankAccount &operator*=(long right) {
        return _assign_operator(right, mul);
    }

    BankAccount &operator/=(long right) {
        return _assign_operator(right, div);
    }

    BankAccount &operator%=(long right) {
        return _assign_operator(right, rem);
    }

private:
    BankAccount &_assign_operator(long right, type_assign type) {
        switch (type) {
            case add:
                volume += right;
                break;
            case sub:
                volume -= right;
                break;
            case mul:
                volume *= right;
                break;
            case div:
                volume /= right;
                break;
            default:
                volume %= right;
        }
        return *this;
    }
};

class Bank {
    enum { max_accounts = 100 };

    BankAccount *acs{nullptr};
    size_t count{0};

public:
    Bank() {
        acs = new BankAccount[max_accounts];
    }

    Bank(BankAccount *lst, size_t size) {
        count = (size > max_accounts) ? max_accounts : size;

        acs = new BankAccount[max_accounts];
        for (int i = 0; i < count; ++i)
            acs[i] = lst[i];
    }

    Bank(const Bank &other) {
        count = other.count;
        acs = new BankAccount[max_accounts];
        for (int i = 0; i < count; ++i)
            acs[i] = other.acs[i];
    }

    const BankAccount *get_accounts() const { return acs; }
    size_t get_count() const { return count; }

    Bank &operator+=(const BankAccount &next) {
        if (count < max_accounts) {
            acs[count] = next;
            ++count;
        }
        return *this;
    }

    Bank operator+(const BankAccount &next) const {
        Bank res = *this;
        res += next;
        return res;
    }

    Bank &operator=(Bank other) {
        swap(other);
        return *this;
    }

    void swap(Bank &other) noexcept {
        std::swap(acs, other.acs);
        std::swap(count, other.count);
    }

    ~Bank() { delete[] acs; }
};

int main() {
    auto *acs = new BankAccount[4]{
        {"А. Дзюба", 43056},
        {"П. Гагарина", 1335395},
        {"О. Бузова", 0},
        {"Тимати", -546}
    };
    Bank my_bank(acs, 4);
    Bank();

    delete[] acs;


    return 0;
}
