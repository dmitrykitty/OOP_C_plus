#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    //labdy moga byc konwertowane automatyczne do ret_type (*func)(get_type)
    //closure type
    auto inc = [](int& x) -> decltype(auto) {
        //decltype(int) -> int&
        ++x;
        return x;
    };

    int x = 0;
    int& y = inc(x);
    std::cout << x;
    //--------------------------------------------------------------------------
    //jka nie przyjmujemy żadnych argumentow-mozna nie pisac okragłe nawiasy
    [] { std::cout << "Hello world"; }(); //immediate invocation
    //complex const inicialization
    const int cnt = [](int y) {
        if (y % 2)
            return y;
        else
            return y / 2;
    }(2024);
    //----------------------------------------------------------------------------
    auto gen = [current = 0, next = 1]() mutable {
        current = std::exchange(next, current + next);
        return current;
    };

    std::vector<int> fib(10);
    std::generate(fib.begin(), fib.end(), gen);
    std::for_each(fib.begin(), fib.end(), [](int n) {
        std::cout << n << " ";
    });
    //----------------------------------------------------------------------------

    std::vector<std::string> v = {"abcd", "dceg", "flmp"};
    std::string sub_str = "fl";

    auto contains_substr = [&sub_str](const std::string& str) {
        //mozna [sub = std::move(sub)] i poza labdą sub jest pusty
        //zeby dostac const referencje [&sub = as_const(sub)]
        //[&sub = std::move(sub)] - CE - lvalue_ref <- rvalue expression

        return str.find(sub_str) != std::string::npos;
    };
    auto iter = std::find_if(v.begin(), v.end(), contains_substr);
    std::cout << *iter;

    //----------------------------------------------------------------------------
    //przekazujemy jako const value, bo u nas const operator()

    std::vector v2 = {1, 2, 2, 5, 7, 9, 9, 11 };
    auto it = std::unique(v2.begin(), v2.end());
    v2.erase(it, v2.end());
    std::for_each(v2.begin(), v2.end(), [](int n){  std::cout << n << " ";});

    //----------------------------------------------------------------------------------------
}
