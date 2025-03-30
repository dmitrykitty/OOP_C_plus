#include <iostream>

class Point {
public:
  int x{0}, y{0};
};

int main() {

  int b{3};
  int a = 7 - b;
  //a i b lvalue - są w pamięci i można im zadawać jakieś wartości
  //połączone z jednostką pamięci
  //zwykłe referencji & moa być tylko na lvalue

  double *ptr_b = new double;
  *ptr_b = 6.4567; //też jest lvalue

  int& count = b; //tez lvalue

  Point pt = {1, 2}; //tez lvalue

  // 7 - b = 10; //rvalue bład

  int& la = a; //referecji tylko na lvalue la = 7-b - błąd
  Point& lpt = pt;
  //Point& lnk_pt = Point(); błąd, bo Point() - tymczasowy obiekt
  //można zrobic referencje typu konst
  const Point& lnk_pt = Point();
  const int& lnk_a = 7 - b; //tez mozna

  //z C++ 11 nowy typ referencji na rvalue - &&
  Point&& lnk_pt2 = Point(); //teraz tymczasowy obiekt point będzie istniał dopoki będzie referencja &&
  int&& lnk_a2 = 7 - b;
  lnk_a2 = 10; //teraz mozna pisac w taki sposob

  //&&rvalue = &lvalue - nie można, ale odwrotnie mozna
  //ale można zrobic tym referencji
  int&& lnk_la = static_cast<int&&>(la); //zmieniamy referencje lvalue la na rvalue
  int&& lnk_la2 = std::move(la); //lub w taki sposob - std::move robi to samo, tyko jest bezpeczniejsza

  return 0;

}