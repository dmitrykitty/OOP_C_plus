#include <functional>
#include <iostream>

void fun(std::function<void()> a) {
    a();
    //dlaczego to jest wolne?
}



int main() {
}