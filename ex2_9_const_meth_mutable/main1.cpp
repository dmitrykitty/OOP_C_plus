#include <iostream>

class Point{
  int x{0}, y{0};
  mutable int z{0}; //mutable zezwala na zmiane wartosci zmiennej w const metodzie

public:
  explicit Point(int x=0, int y=0): x(x), y(y){ }

  void set_coords(const Point& p){ //skoro const referencja - p nie będzie sie zmieniał
    //dlatego nie działają tu żadne metody klasa Point, p.get_coords(x, y);
    //jak metod nie zmienia obiektu, a tylko pozwala sczytywac dane - const
    x = p.x;
    y = p.y;
  }
  int get_x() const { return x; }//zwracana jest kopia ktora nie wpływa na stan zmiennej
  int get_y() const { return y; }

  const int& get_x_ref() const { return x; } //jak referencje lub wskazniki w const metodzie
  const int* get_y_ptr() const { return &y; }//tez mają być const, żeby nie można było zmienic ich wartosci

  void get_coords(int& x, int& y) const {
    //w const metodach mozna wywoływac tylko konst metody
    x = get_x();
    y = get_y();
    z++; //zwieksza się gdy jest wywoływana ta metoda
  }
  int get_z() const { return z; }//zwracany typ wszystko jedno int!!!

};

int main(){
  Point p1(1,2), pt;

  pt.set_coords(p1);

  int x, y;
  pt.get_coords(x, y);
  std::cout << x << " " << y << std::endl;
  std::cout << pt.get_z() << std::endl;



  return 0;

}
