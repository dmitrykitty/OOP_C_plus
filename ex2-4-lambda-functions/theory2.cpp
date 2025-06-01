#include <iostream>

constexpr int len = 100;


int main() {
    int size = 5;
    auto r = [=]() { std::cout << len + size; };
    // [=] - tworzy sie const kopia wszystkich lokalnych zmiennych, aby mozna było zmienic size wewnatrz
    //po () mutable {function body}
    //mozna przekaszac nie wszystkie zmienne, a tylko jakies konkrente [size, len]
    r();
    auto p = [size]() mutable { size += 5; std::cout << size; };
    p();
    std::cout << size;

    auto ref = [&size]() { size += 6; };
    //zwiekszwenie bezposrednio size, lub mozna dac [&], zeby wszystkie zmienne były jako referencje
    ref();
    std::cout << size;

    //mozna tez kombinowac [=, &size, &len] lub [&, size, len]
}
