#include <iostream>

class GamePole {
    int rows{0}, cols{0};
    char* pole{nullptr};
public:
    GamePole(int row, int col) : rows(row), cols(col) {
        pole = new char[rows*cols]{0};
    }
    GamePole(const GamePole& other) : GamePole(other.rows, other.cols) {
        for (int i = 0; i < rows*cols; i++)
            pole[i] = other.pole[i];
    }
    void set_item(int row, int col, char value){
        pole[row * cols + col] = value;
    }
    char get_item(int row, int col) const { return  pole[row * col + col]; }
    const char* get_pole() const { return pole; }

    void get_size(int& rows, int& cols) const {
        rows = this->rows;
        cols = this->cols;
    }
    ~GamePole() { delete pole; }
};




int main(void)
{
    GamePole gp(10, 7);
    gp.set_item(3, 5, '#');
    gp.set_item(4, 2, '*');
    gp.set_item(4, 4, '*');


    // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}