#include <iostream>
#include <numeric> // dla std::accumulate

int sum_ar(short* ar, size_t size){
    short sum = std::accumulate(ar, ar + size, static_cast<short>(0)); //begin, end, value of sum
    if(sum == 0)
        throw "Array length is zero.";
    return sum;
}

int main()
{
    short ar[] = {-1, 0, 10, 5, 3, 2};
    try {
        short sm = sum_ar(ar, std::size(ar));
        std::cout << sm << std::endl;
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }


        return 0;
    }