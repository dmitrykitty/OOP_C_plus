#include <fstream>
#include <iostream>

int perimetr(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0){

        //nie zawsze mozna wymysliec co zwrocic jako błąd
        throw -1;
        //po throw funckja konczy działanie
        //dzaiłanie przekazuje się zewnętrznej funkcji gdzie została wywołana nasza funckja(tutaj main)
        //tam wywołuje się funkcja
        //std::terminate(); po niej
        //std::abort(); powoduje ze cały program konczy działanie
        //zeby programa sie nie przerywała awaryjnie, mamy złapac ten exception za pomocą try{} catch{}
        //dalszy ciąg programy

    }
    if (a > b + c || b > a + c || c > a + b) {
        throw "Error: incorrect arguments";
    }
    return a + b + c;
}

void load_data(const char* path, int& x) {
    std::ifstream ifs;
    ifs.exceptions(std::ios::failbit); //dla generacji exceptions

    try {
        ifs.open(path);
        ifs >> x;
        ifs.close();
    } catch (...) {
        //najpierw ten blok exception, poźniej block w main
        ifs.close();
        throw;
    }
}

int main() {

    try {
        int p = perimetr(1, -2, 5);
    } catch(const char* e) {
        std::cout << e << std::endl;
    } catch (int) {
        std::cout << "Length of the side must be positive" << std::endl;
    }
    // bloki catch sprawdzane od gory, moze zadziałac tylko jeden


    int data{};

    try {
        load_data("123", data);
        std::cout << data << std::endl;
    } catch (const std::exception& e) {
        //obiekt typu exception const std::exception e
        std::cout << "Error read data from file" << std::endl;
    }

    return 0;
}
