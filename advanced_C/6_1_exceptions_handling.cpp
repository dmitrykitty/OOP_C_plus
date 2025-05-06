#include <iostream>

struct A {
    A() { std::cout << "A" << std::endl; }
    A(const A& a) { std::cout << "Acopy" << std::endl; }
    ~A() { std::cout << "~A" << std::endl; }

};

void f(int x) {
    A a; //tworzenie na stacku
    if (x == 0)
        throw a; //copy to dynamic memory(heap) (GCC uzywa malloc)
}


int main(){
    try {
        f(0);
    } catch (A& a) {
        //jak ... brak kopii
        //jak A a -> kopia z powrotem do stacku
        //jak const A& a -> brak kopii i dalej praca w dynamic memory
        std::cout << "Caught" << std::endl << &a << std::endl;
        throw; //jak napisze throw a - tworzenie nowego obiektu oraz usuniecie starego
        //kolejne catch are ignored
    }
    return 0;
  }