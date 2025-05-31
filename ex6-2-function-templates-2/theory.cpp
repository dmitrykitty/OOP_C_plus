#include <iostream>

template<typename T1, typename T2>
auto sq_rect(T1 a, T2 b) {
    return a * b;
}

template<typename RT = double, typename T1, typename T2>
RT sum(T1 a, T2 b) { return a + b; }


template<int calc_type = 1, typename T1, typename T2>
auto get_rect_info(T1 a, T2 b) {
    return calc_type == 1 ? a + b : a * b;
}

template<typename T, size_t LEN> //automatycznie odczytuje długość
T ar_sum(const T (& ar)[LEN]) {
    std::cout << LEN << std::endl;
    T res = 0;
    for (size_t i = 0; i < LEN; ++i)
        res += ar[i];
    return res;
}


//template overloading
template<typename T>
T add(T a, T b) {
    std::cout << "add 1" << "\n";
    return a + b;
}

template<typename T>
T add(T* a, T* b) {
    std::cout << "add 2" << "\n";
    return *a + *b;
}

template<typename T1, typename T2>
auto add(T1 a, T2 b) {
    std::cout << "add 3" << "\n";
    return a + b;
}

int add(int a, int b) {
    std::cout << "add 4" << "\n";
    return a + b;
}



int main() {
    double res_1 = sq_rect(5, 6.5); //zwracany typ - double
    double res_2 = sq_rect(5, 6); //zwracany typ - int
    short res_3 = sq_rect<short, short>(5, 6); //zwracany typ int, bo a * b konwersja do int
    short res_4 = sq_rect<double>(3, 4); //zwracany typ double, bo 3 typu double, a double * int -> double

    double sum_1 = sum(5, 6.5); //zwracany typ - double
    double sum_2 = sum(5, 6); //zwracany typ - double, bo jawnie wskazany typ doubke jakjo RT
    short sum_3 = sum<short>(5, 6); //zwracany typ short, bo RT - pierwszy parametr
    double sum_4 = sum<int>(3.5, 4.2); //zwracany typ int, ale typeid(a, b) = double

    double per_1 = get_rect_info(5, 6.5); //zwrocono perimetr typ double
    double sq_1 = get_rect_info<2>(5, 6); //zwrocono area typ int

    double ar_1[]{1.1, 2.2, 3.4, 5.6, 6.4};
    int ar_2[]{1, 2, 3, 5, 6, 7, 8, 9};

    ar_sum(ar_1);
    ar_sum(ar_2);

    add(5, 6); //add4
    add(5, 6.5); //add3
    add(5.5, 6.6); //add1
    int a = 5, b = 7;
    add(&a, &b); //add2

    //im dokladniej jest opisany template/funkcja -> większa szansa na wywołanie

    return 0;
}
