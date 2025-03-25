#include <vector>

int main()
{
  std::vector<int> v1;              // пустой вектор
  std::vector<int> v2(v1);          // вектор v2 - копия вектора v1
  std::vector<int> v3 = v1;         // вектор v3 - копия вектора v1
  std::vector<int> v4(5);           // вектор v4 состоит из 5 чисел, каждое число равно 0
  std::vector<int> v5(5, 2);        // вектор v5 состоит из 5 чисел, каждое число равно 2
  std::vector<int> v6{1, 2, 4, 5};  // вектор v6 состоит из чисел 1, 2, 4, 5
  std::vector<int> v7 = {1, 2, 3, 5}; // вектор v7 состоит из чисел 1, 2, 3, 5
  int f = v7.front(); //zwraca pierwszy element
  int b = v7.back(); //zwraca ostatni element
  v7.push_back(6); //dodaje element na koniec
  v7.pop_back(); //usuwa ostatni element
  v7.reserve(100); //zarezerwuje miejsce na 100 elementow
  v6.at(2) = 10; //zamienia element na pozycji 2 na 10
  v7.shrink_to_fit(); //zmniejsza rozmiar v7 do rozmiaru wymaganego do przechowywania elementow
  v7.clear(); //usuwa wszystkie elementy z v7 - size = 0, capasity jak było
  v7.reserve(1000); //zarezerwuje miejsce na 1000 elementow
  v7.resize(100, 5); //zmienia rozmiar v7 na 100 elementow
  //istniejace elenty sie nuie zmianiała, jak pusty, wypełnia 100 elementami = 5



  return 0;
}