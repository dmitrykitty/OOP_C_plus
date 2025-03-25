#include <string>

int main()
{
  std::string s = "Hello World!"; //na koncu \0, index [size]
  char m = s.at(10); //zwraca znak na pozycji 10 ze sprawzdeniem czy moze on byc
  //jak nie - zwroci out of range
  s.at(3) = 'a'; //zamienia znak na pozycji 3 na 'a'
  s.push_back('!'); //dodaje znak na koniec
  s.pop_back(); //usuwa znak na koncu
  s.back() = 'r'; //zwraca ostatni znak
  s.front() = 'H'; //zwraca pierwszy znak
  return 0;
}