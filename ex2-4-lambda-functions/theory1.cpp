//[](params){function body} (mozna dodac jak chce sie od razu wywołac labda funkcje)


#include <iostream>

void show_ar(const int* ar, size_t size, bool (* filter)(int) = nullptr) {
    for (size_t i = 0; i < size; ++i) {
        if (filter) {
            if (filter(ar[i]))
                std::cout << ar[i] << " ";
        } else {
            std::cout << ar[i] << " ";
        }
    }
}

int main() {
    [](int a) {
        std::cout << "My first lambda " << a << std::endl;
    }(10);


    auto r = [](int a) {
        std::cout << "My first lambda " << a << std::endl;
    };

    r(12); //wywołanie lambda funkcji przez r(obiekt funkcji)
    auto s = r; //juz inna lambda
    s(9);

    auto t{
        [](const char* msg, int& x) {
            std::cout << msg << " " << x << std::endl;
            ++x;
        }
    };
    int x = 0;
    t("Krinjjjjjj", x);

    //mozna zwracac wartosci
    auto b{
        [](const std::string_view& msg) {
            std::cout << msg << std::endl;
            return msg.size();
        }
    };

    auto sum2{[](int a, int b)-> double { return a + b; }};
    //mozna jawnie wskazywac typ zwracany

    size_t len = b("The longest msg");
    std::cout << len << std::endl;


    auto newsum2{[](const auto& a, const auto& b) { return a + b; }};
    std::cout << newsum2(1, 5) << std::endl;
    std::cout << newsum2(1.5, 5.8) << std::endl;
    std::cout << newsum2(std::string("Dima"), std::string("Lox")) << std::endl;

    const int ar[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    show_ar(ar, std::size(ar), [](int a) { return a > 2 && !(a % 2); });
    std::cout << std::endl;
    show_ar(ar, std::size(ar));

    return 0;
}
