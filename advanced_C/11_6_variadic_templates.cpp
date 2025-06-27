#include <iostream>

void print() {} //kiedy juz nie ma zadnych argumentow
template<typename Head, typename... Types> //Types to pakiet typow(inicjalizacja pakietu)
void print(const Head& head, const Types&... tail) {
    //otwieranie pakietu(moze byc pusty)
    //ta funkcja pasuje, gdy jest chociaz by head lub tail
    std::cout << head << ' ';
    print(tail...);
}

//------------------is_homogeneous-----------------------------

template<typename First, typename Second, typename ...Types>
struct is_homogeneous {
    static constexpr bool value = std::is_same_v<First, Second>
    && is_homogeneous<Second, Types...>::value;
};

template<typename First, typename Second> //sprecjalizacja, zeby nie było nuby pzeciozenia struktury
struct is_homogeneous<First, Second> {
    static constexpr bool value = std::is_same_v<First, Second>;
};

int main() {}
