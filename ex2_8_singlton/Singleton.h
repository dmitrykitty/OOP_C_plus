#include <iostream>
#ifndef SINGLETON_H
#define SINGLETON_H

class SingletonData {
  SingletonData() = default;
  SingletonData(const SingletonData& ) = default;
public:
  const SingletonData& operator=(const SingletonData& ) { return *this; }
  static SingletonData* get_instance()
  {
    static SingletonData obj;
    return &obj;
  }
};


class Singleton {
  int data{0};
  static Singleton* instance_ptr; //statyczny wskaznik

  Singleton() = default; //prywatny konstruktor domyślny

public:
  Singleton(const Singleton&) = delete;

  void set_data(int d){ data = d; }
  int get_data(){ return data; }

  ~Singleton(){
    instance_ptr = nullptr;
    std::cout << "Object has been removed. Now you can create new one." << std::endl;
  } //destruktor

  static Singleton* get_instance(){ //da sie stworzyc tylko jezeli ptr = nullptr
    if(!instance_ptr)
      instance_ptr = new Singleton();
    return instance_ptr;
    }

};



#endif //SINGLETON_H
