#include <future>
#include <iostream>
#include <memory>

struct thing {
    unsigned long uid;
    unsigned width, height, depth;
};

struct object {
private:
    short data;
    object* next;
public:
    object(short d): data(d), next(nullptr){}

    object* get_next() const { return next; }
    short get_data() const { return data; }

    void set_next(object* ptr) { next = ptr; }
    void set_data(short d) { data = d; }
};


int main() {


    std::unique_ptr<int> ptr;
    std::unique_ptr<int> ptr2{}; //to samo - nullptr
    std::unique_ptr<int> ptr3{std::make_unique<int>(10)}; //mozna inicjalizowac w miejscu
    //mozna wydzielac pamiec przez new int ..., ale moze byc podowjne zwolnienie pamieci
    //pamiec alokowana znajduje sie na stercie, a sam wskaznik na stosie

    if (ptr)
        std::cout << *ptr << std::endl;
    else
        ptr = std::make_unique<int>(1); //alokuje pamiec typu int i zapisuje tam wartosc 10
    //dla uniq_ptr operator= overloaded. gdy wydzielona nowa pamiec - stara automatycznie oczyszczana

    ptr2 = ptr3; //błąd, bo ma byc uniq ptr, więc tylko jeden pointer na jeden adres pamieci

    //ale mozna najebac kompilator
    int* p = new int(5);
    std::unique_ptr<int> ptr4{p};

    //METODY UNIQ_PTR
    int* p2 = ptr2.get(); //zwraca raw wskaznik
    int* p3 = ptr2.release(); //zwraca wskaznik i odpina smart ptr, nie zwalniajac pamiec
    ptr2.reset(); //zmienia na nowy adres lub nullptr, jak nic nie prakazuje sie do metody
    ptr3.swap(ptr); //zwapuje wskazniki

    int total{10};
    std::unique_ptr<int[]> ar_p{std::make_unique<int[]>(total)};
    auto ar_p2{std::make_unique<int[]>(total)};
    std::unique_ptr<int[]> ar_p3{nullptr};

    thing t;
    std::unique_ptr<thing> p_th{std::make_unique<thing>(t)};
    p_th->uid = 1;
    p_th->width = 10;

    //---------------------------------------------------------

    object o1(1), o2(2);

    std::unique_ptr<object> top{std::make_unique<object>(o1)};
    std::unique_ptr<object> ptr5{std::make_unique<object>(o2)};

    top->set_next(ptr5.get()); //przekazanie raw ptr do methoda





    return 0;
}
