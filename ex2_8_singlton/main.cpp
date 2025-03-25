#include "Singleton.h"
#include <iostream>

int main(){
  Singleton* s = Singleton::get_instance(); // tworzenie obiektu Singleton

  std::cout << s << std::endl;
  s->set_data(10);
  std::cout << s->get_data() << std::endl;

  delete s; // usuniecie obiektu Singleton. zeby wskaznik był nullptr


  return 0;
}