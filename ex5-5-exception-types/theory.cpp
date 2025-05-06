#include <iostream>

class CardError: std::exception {
    std::string msg;

public:
    explicit CardError(const char* msg) : msg(msg) {}

    CardError(const CardError& other) = default;

    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
};

class CardLenghtError : public CardError {
public:
    explicit CardLenghtError(const char* msg) : CardError(msg) {}
};

class CardFormatError : public CardError {
public:
    explicit CardFormatError(const char* msg) : CardError(msg) {}
};

class  CardNumberError: public CardError {
public:
    explicit CardNumberError(const char* msg) : CardError(msg) {}
};



class BancCard {
    const int length_number{19};
    std::string number;

    void verify_number(const std::string& num) const {
        if (num.length() != length_number) {
            throw CardLenghtError("incorrect card length");
        }

        const char* p = num.c_str();
        for (int i = 0; i < length_number; i++) {
            if (i == 4 || i == 9 || i == 14)
                if (p[i] != '-')
                    throw CardFormatError("only numbers allowed");
            if (p[i] < '0' || p[i] > '9')
                throw CardNumberError("only numbers allowed");
        }
    }

public:
    void set_number(const std::string& num) {
        verify_number(num);
        number = num;
    }

    const std::string& get_number() const { return number; }
};


int main() {
    BancCard card;
    try {
        card.set_number("123775678-9533-4563");
    } catch (const CardLenghtError& err) {
        //mozna tez przyjmowac const int lub const int& lub int&
        //tutaj nie dzaiła żadnego niejawnego castu
        std::cout << err.what() << std::endl;
    } catch (const CardFormatError& err) {
        //dla const ma byc tylko const
        std::cout << err.what() << std::endl;
    } catch (const CardNumberError& err) {
        std::cout << err.what() << std::endl;
    } catch (const CardError& err) { //ten z klasem bazowem zawsze na koncu
        std::cout << "CardError:" << err.what() << std::endl;
    } catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
