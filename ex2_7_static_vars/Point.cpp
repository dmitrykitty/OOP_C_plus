
#include "Point.h"

void Point::set_coords(int x, int y){
    if(check_coord(x) && check_coord(y)){
        this->x = x;
        this->y = y;
    }
}

int Point::MIN_COORD{0};
int Point::MAX_COORD{10};