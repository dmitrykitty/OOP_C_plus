#include <iostream>

enum {max_length_ar = 20};
using filter_func = bool (*)(short);

void remove_elem(short* ar, int& len, filter_func filter)
{
    int removed = 0;
    for(int i = len - 1; i >= 0; --i){
        if(filter(ar[i])){
            for(int j = i; j < len - 1; j++)
                ar[j] = ar[j + 1];

            ++removed;
        }
    }
    len -= removed;
}


int main() {
    short marks[max_length_ar] = {};
    int count = 0;
    while(count < max_length_ar && std::cin >> marks[count])
        count++;

    remove_elem(marks, count, [](short a){ return a < 3;});
}
