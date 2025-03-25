#include <iostream>
#include <cstring>

class S {
  size_t capacity{};
  size_t size{};
  char *data{};

public:
  S(const char* s): capacity(strlen(s) + 1), size(capacity - 1), data(new char[capacity]{}) {}
  S(const S& other): S(other.data) {} // konstruktor kopiujący
  S(S&& other): S(other.data) {} //konstruktor przenoszący

};
