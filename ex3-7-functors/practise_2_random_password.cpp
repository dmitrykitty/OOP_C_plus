#include <iostream>
#include <utility>
#include <random>

class RandomPassword {
    std::string pswd_chars_;
    int min_length_{}, max_length_{};
    std::mt19937 gen_; //random engine

public:
    RandomPassword(std::string chars, int min, int max)
        : pswd_chars_(std::move(chars)),
          min_length_(min),
          max_length_(max),
          gen_(std::random_device{}()) {} //seed

    std::string operator()() {
        std::uniform_int_distribution<int> len_dist(min_length_, max_length_);
        //class uniform... and functor len_dist
        int length = len_dist(gen_);

        std::string res;
        res.reserve(length);

        int len = static_cast<int>(pswd_chars_.size());
        std::uniform_int_distribution<int> char_dist(0, len - 1);

        for (int i = 0; i < length; i++) {
            res += pswd_chars_[char_dist(gen_)];
        }
        return res;
    }
};

int main() {
    RandomPassword rnd("qwertyuiopasdfghjklzxcvbnm0123456789!@#$%&*", 5, 15);

    std::cout << rnd() << " " << rnd();

    return 0;
}
