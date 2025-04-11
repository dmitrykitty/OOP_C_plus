#include <iostream>

class Time {
    unsigned long time{0};

public:
    Time() = default;

    Time(unsigned char hours, unsigned char minutes, unsigned char seconds): time(hours * 3600 + minutes * 60 + seconds) {}

    Time(unsigned long t): time(t){}


    Time operator+(const Time &right) const //typ operaotr<>(przekazana wartość, w sumie po prawej stronie)
    //this po lewej stronie
    //nie mozna zwracac const referencji, bo tworzony obiekt znajduje sie wewnatrz ciała wfunkcji
    {
        return {this->time + right.time};//mozemy napisac (time + 10) iwszystko będzie działac
        //ponieważ mamy kosntruktor z jednym parametrem, ktory z 10 tworzy obiekt typu Time
        //ale nie mozna (10 + time), bo mamy 10.operator+(time), nie możemy miec metody u liczby - rozwiazanie inna funkcja
    }



    void get_time(unsigned char &hours, unsigned char &minutes, unsigned char &seconds) const
    {
        hours = time / 3600;
        minutes = time / 60 / 60;
        seconds = time % 60;
    }

    void show_time() const
    {
        printf("%02d:%02d:%02d\n", int(time / 3600), int(time / 60 % 60), int(time % 60));
    }
    friend Time operator+(const Time& left, const Time& right);
};

Time operator+(const Time& left, const Time& right)
{
    return {left.time + right.time};
}//ale w takim przpadku nie musi istniec poprzednia funkcja z operatorem
//aby ta globalna funkcja miała dostep do pol prywatnych dwoch roznych obiektow
// fiend prototyp();

int main()
{
    Time t(10, 54, 49), t2(1024);
    t.show_time();
    t2.show_time();
    Time sum = t + t2;
    //a mozna tak Time sum = t.operator+(t2)
    sum.show_time();
    Time sum2 = 154 + 136;
    sum2.show_time();


    return 0;
}
