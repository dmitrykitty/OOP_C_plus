#include <algorithm>
#include <iostream>
#include <compare>
#include <vector>

struct Complex {
    double re{};
    double im{};

    Complex(double re = 0): re(re) {}
    Complex(double re, double im): re(re), im(im) {}

    /*to samo, co c.operator+(other)
    jest problem - nie mozna 3.14
     Complex operator+(const Complex &other) const {
         return Complex(re + other.re, im + other.im);
    } */
    friend Complex operator+(const Complex &x, const Complex &y);

    //EXTENDED += -= *= /= %= ...
    Complex &operator+=(const Complex &y) {
        /* nigdy nie mozna robic tak(używając już przeciążonego +
        działa bardzo wolno, 3-krotne kopiowanie
        *this = *this + other;
        tutaj tworzono string(zakładamy, ze mamy string) *this + other z kopiamy,
        a poznie to kopiujemy do *this.
        += szybkie, działa od O(1), a + za 0(n)
        więc zwykł + wyrażany przez +=
        return *other */
        re += y.re;
        im += y.im;
        return *this;
    }

    //-----------------------------------------------------------

    Complex &operator=(const Complex &other) & = default;

    //-----------------------------------------------------------
    //OPERATOR ++A, A++

    Complex &operator++() {
        ++re;
        ++im;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    //-----------------------------------------------------------

    //operator<=> SpaceShip(nieof) lub Three-way comparison(od C++ 20)
    //od razu wszystkie operatory porownawcze leksyko-graficznedziałają
    //działa szybciej
    auto operator<=>(const Complex &other) const = default;

    //sposob na porownanie char* ze stringiem
    //jezeli saceship nie jest default, operatory > < >= <= definiują sie automatycznie,
    //a == != nie xD
    //bo np dla stringow nie trzeba powornywac całe stringi, bo wystarczy porownac size i będzie działać szybciej
    std::weak_ordering operator <=>(const char *) const {
        return std::weak_ordering::equivalent;
    }

    //jak jest auto - ordering wybrany samodzielnie
    //moze byc stong ordering, weak odreirn, partial ordering
    //w strong ordering: a = b <=> f(a) = f(b)
    //w weak orderin: a = b nie oznacza, że wszystkie pola klasy są równe

    bool operator==(const Complex &other) const = default;

    //porownanie pol klasy
};

//----------------------------------------------------------------
//BINARY + - / *
Complex operator+(const Complex &x, const Complex &y) {
    Complex result = x;
    result += y;
    return result;
    //return Complex(x.re + y.re, x.im + y.im);
    //inny sposob

    //dlaczego nie można return x+=y?
    //będzie dodatkowe kopiowanie i działa za 0(N)

    /*
    a + b = c - działa, dlaczego?
    po lewej stronie r-value
    ale dlaczego nie można dla swoich typow pisac rvalue = coś?
    dwa rozwiązanie, żeby nie mozna było tak robić:

    const Complex operator+(const Complex& x, const Complex& y) {
    bo nie mozeny const cos = cos innego, ale lepiej tak nie robic

    inne rozwiązanie
    do operator= wskazac, że mozna go uzywac tylko dla lvalue
    Complex& operator=(const Complex &other) & {}
    po (const ...) & - tylko dla lvalue, && - tylko dla rvalue
    */
}

//--------------------------------------------------------------------
//OPERATOR OSTREAM, ISTREAM
//poza funkcj ma być
std::ostream &operator<<(std::ostream &out, const Complex &x) {
    out << "(" << x.re << ", " << x.im << ")";
    return out;
}

//-------------------------------------------------------------------
//OPERATOR > < == >= <=
bool operator<(const Complex &x, const Complex &y) {
    return x.re < y.re || x.re == y.re && x.im < y.im;
    //jest wynagany, by dodaj swoje obiekty do hash-map lub set
    //wszystko wyraza się przez <
}

bool operator>(const Complex &x, const Complex &y) {
    return y < x;
}

//== !(b < a)&&!(a < b)


//--------------------------------------------------------------------
//operator comma(np skalarna suma wektorow)


//--------------------------------------------------------------------
//OPERATOR ()()FUNCTORS
//mozba go przekazywac jako comporator do funkcji sortujących
/*
Complex a(1, 5), b(2, 2), c(4, 1);
std::vector<Complex> v(3);
v.push_back(a);
v.push_back(b);
v.push_back(c);
std::sort(v.begin(), v.end(), Greater());
*/

struct Greater {
    bool operator()(const Complex &x, const Complex &y) const {
        return x > y;
    }
};

int main() {
    Complex a(1, 5), b(2, 2), c(4, 1);

    std::vector<Complex> v(3);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    std::sort(v.begin(), v.end(), Greater());

    std::cout << a << std::endl; //(1, 5)
}
