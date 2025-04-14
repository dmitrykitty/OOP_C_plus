#include "DArray.h"
#include <iostream>

int main() {
    DArray array1, array2;

    for (int i = 0; i < 10; i++)
        array1.push_back(i + 1);

    array2 = array1;
    std::cout << array2.get_size() << " " << array2.get_capacity() << std::endl;
    for (int i = 0; i < array2.get_size(); i++) {
        std::cout << array2.get_data()[i] << " ";
        array2[i] += array2[i] % 5;
    }


    std::cout << std::endl << array1[5] << std::endl;
    array1.pop_back();
    array1.pop_back();
    array1.pop_back();
    array1[12] = 25;
    array1 += array2;
    for (int i = 0; i < array1.get_size(); i++)
        std::cout << array1[i] << " ";

    return 0;
}
