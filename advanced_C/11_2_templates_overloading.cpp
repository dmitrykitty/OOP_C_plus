template <typename T>
void f(T x){}

void f(int x){}
//im dokładniej jest opisana sygnatura funkcji, będzie ona wywołana
//pisząc wybor typu w <> - będzie wywołana template wersja
//szablony o jednakowych sygnaturach, ale roznych zwracanych typach się kompilują,
//ale nie da się je wywołać

int main() {
    int x = 0;
    f(x); //będzie wywołana 2 funkcja
}
