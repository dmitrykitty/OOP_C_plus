#include <iostream>

class Point {
  int x, y;
public:
  static unsigned counter; //deklaracja statycznej zmennej
  //moze byc rowniez private, ale wtedy trzeba zrobit getter


  Point(int x=0, int y=0): x(x), y(y) {
    counter++;
    std::cout << counter << std::endl;
  }
  ~Point(){
    counter--;
    std::cout << counter << std::endl;
  }
  static unsigned get_counter(){ return counter; }
  //nie ma dosdtepu do this

};

unsigned Point::counter = 0; //incjalizacja static zmiennej

int main(){

  Point p1, p2, p3;
  /*
   1
   2
   3
   2
   1
   0
   */


  return 0;
}