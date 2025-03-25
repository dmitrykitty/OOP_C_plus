
#ifndef POINT_H
#define POINT_H



class Point {
    int x{0}, y{0};
    static int MIN_COORD;
    static int MAX_COORD;

    bool check_coord(int coord){
        return coord < MAX_COORD && coord > MIN_COORD ? true : false;
    }

public:

    Point(int x=0, int y=0){
        if(check_coord(x) && check_coord(y)){
            this->x = x;
            this->y = y;
        }
    }

    static void set_bounds(int left, int right){
        MIN_COORD = left;
        MAX_COORD = right;
    }

    static void get_bounds(int& left, int& right){
        left = MIN_COORD;
        right = MAX_COORD;
    }

    void set_coords(int x, int y);

    int get_x(){ return x; }
    int get_y(){ return y; }

};



#endif //POINT_H
