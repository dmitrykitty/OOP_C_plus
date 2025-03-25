#include "PointND.h"
#include <iostream>



const PointND& PointND::operator=(const PointND& other){
    if(this == &other)
        return *this;

    delete[] coords;
    total = other.total;
    coords = new int[total] {0};
    set_coords(other.coords, total);
    std::cout << "redefinicja = dla dwoch obiektow klas" << std::endl;
    return *this;
}

void PointND::set_coords(int *c, unsigned n){
    if(c != nullptr && n > 0)
        for(unsigned i = 0; i < n; i++)
            coords[i] = c[i];
}
unsigned PointND::counter = 0;