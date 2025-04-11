#include <iostream>
#ifndef POINTND_H
#define POINTND_H



class PointND {
    unsigned total {0};
    int* coords{nullptr};
public:
    static unsigned counter;

    static unsigned get_counter(){ return counter; }

    PointND(unsigned n): total(n){
        coords = new int[n] {0};
        std::cout << "konstruktor konwersji" << std::endl;
        counter++;
    }

    PointND(int *c, unsigned n): PointND(n) {
        std::cout << "konstruktor z 2 parametrami" << std::endl;
        set_coords(c, n);
        counter++;
    }

    PointND(const PointND& other): PointND(other.coords, other.total){
        std::cout << "konstruktor kopiujacy" << std::endl;
        counter++;
    }

    ~PointND()
    {
        delete[] coords;
        counter--;
    }

    unsigned get_total(){ return total; }
    const int* get_coords(){ return coords; }

    const PointND& operator=(const PointND& other);
    void set_coords(int *c, unsigned n);
};






#endif //POINTND_H
