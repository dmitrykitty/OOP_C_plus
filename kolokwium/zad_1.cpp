#include <cstdint>
#include <iostream>
using namespace std;
static void testDifferentAnd()
{
    const int a = 1, b = 2;
    cout << noboolalpha << (a&b) << (a&&b) << endl;
}
struct A
{
    static inline uint32_t livingInstances;
    A() { cout << "A::A()\n"; livingInstances++; }
    A(const A& a) { cout << "A::A(copy)\n"; livingInstances++; }
    A(const A&& a)  noexcept { cout << "A::A(copy)\n"; livingInstances++; }
    ~A() { cout << "A::~A()\n"; livingInstances--; }
};
int main() {
    {
        cout << string(10, '-') << "1:\n";
        testDifferentAnd();
        A b = A();
    }
}