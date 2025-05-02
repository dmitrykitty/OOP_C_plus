#include <fstream>
#include <iostream>

int perimetr(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) {
        //nie zawsze mozna wymysliec co zwrocic jako błąd
        throw -1;
        //po throw funckja konczy działanie
        //dzaiłanie przekazuje się zewnętrznej funkcji gdzie została wywołana nasza funckja(tutaj main)
        //tam wywołuje się funkcja
        //std::terminate(); po niej
        //std::abort(); powoduje ze cały program konczy działanie
        //zeby programa sie nie przerywała awaryjnie, mamy złapac ten exception za pomocą TRY CATch
    }
    if (a > b + c || b > a + c || c > a + b) {
        throw "Error: incorrect arguments";
    }
    return a + b + c;
}

class Exception {
public:
    inline static int count_create = 0;
    inline static int count_delete = 0;

    Exception(){ count_create++; }
    Exception(const Exception& e){ count_create++; }
    //wymagany konsturktor kopiujący
    ~Exception(){ count_delete++; }
};

void load_data(const char* path, int& x) {
    std::ifstream ifs;

    try {
        ifs.open(path);
        if (!ifs.is_open()) {
            throw Exception(); //tworzenie pierwszego exception
        }
        ifs >> x;
        ifs.close();
    } catch (const Exception& e) { //towrzenie drugiego exception
        ifs.close();
        throw;//tworzenie trzeciego oraz usuniecie pierwszego i drugiego
    }
}

int main() {
    try {
        int p = perimetr(1, -2, 5);
    } catch (const char* e) {
        std::cout << e << std::endl;
    } catch (int) {
        std::cout << "Length of the side must be positive" << std::endl;
    }
    // bloki cathc sprawdzane od gory, moze zadziałac tylko jeden


    int data{};

    try {
        load_data("123", data);
        std::cout << data << std::endl;
    } catch (const Exception& e) {
        std::cout << Exception::count_create << std::endl; //4
        std::cout << Exception::count_delete << std::endl; //2
    }
    //tutaj usuniecie trzeciego oraz czwartego exception
    //gdybym przekazywał obiekty jako referenji - zsotało by stworzono i usunięto tylko 2 obiekty

    //jak piszemy drugi throw bez paramentrow - nie tworzy się dodfaktowy obiekt -
    //jako wynik stworzony bedzie tylko jeden obiekt Exception

    //kiedy mamy jakis exception np w load_data - we wszystkich obiektach stworzonych w stack frame są wywoływane
    //konstruktory - tutaj dla std::ifstream ifs
    //jak jest throw exception in constructor - nie będzie wywołany destructor, bo obiekt nie zostanie w pełni utworzony
    //
    return 0;
}
