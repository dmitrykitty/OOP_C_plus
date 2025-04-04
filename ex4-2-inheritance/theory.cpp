#include <iomanip>
#include <iostream>
#include <valarray>

class GeomBase {
protected:
    int x0{}, y0{}, x1{}, y1{};

public:
    GeomBase() = default;

    GeomBase(int x0, int y0, int x1, int y1): x0(x0), y0(y0), x1(x1), y1(y1) {}

    void set_coords(int x0, int y0, int x1, int y1) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }

    void get_coords(int &x0, int &y0, int &x1, int &y1) const {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
};

class Line : public GeomBase {
    //by default : private GeomBase
    //wysztko, co jest w klasie GeomBase będzie private i niedostępne z Line
    //GeomBase *g = (GeomBase*)ln; -rzutowanie typow
    double length{};

public:
    Line(int x0, int y0, int x1, int y1): GeomBase(x0, y0, x1, y1), length(0) {}

    Line() = default;

    void set_coords(int x0, int y0, int x1, int y1) {
        GeomBase::set_coords(x0, y0, x1, y1); //a tu jest metoda s klasy bazowej
        std::cout << "Line set_coords" << std::endl;
    }

    //przeciązenia metody z klasy bazowej


    void get_info() {
        length = std::sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
        printf("x0:%d y0:%d, x1:%d y1:%d ", x0, y0, x1, y1);
        std::cout << "Length: " << std::fixed << std::setprecision(2) << length << std::endl;
    }
};

int main() {
    int x0{}, y0{}; //przeciazenie zmiennych '
    /*teraz obiekt klasa wygląda tak
     * GeomBase:
     *      x0, y0, x1, y1
     * line:
     *      x0, y0, length
     * kiedy jest wywołany obiekt Line - kompilator szuka najpierw szuka zmiennych i metod line;
     */
    Line *ln = new Line();
    ln->set_coords(1, 3, 8, 12); //polimorfizm(uzycie metod klasy bazowej)
    //napierw zmienne z klasy bazowej, a pozniej dzedziczonej
    ln->get_info();
    GeomBase *g = ln;
    //tutaj nie sa dostepne zmienne i metody klasy dziedziczonej

    delete ln;
    return 0;
}
