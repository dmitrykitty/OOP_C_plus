#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    double pow[] {4.3, -5.4, 0.01, 7.88};
    std::ofstream out("binary.txt", std::ios::out | std::ios::binary);

    if (out.is_open()) {
        out.write(reinterpret_cast<char* >(pow), sizeof(pow));
    }

    out.close();

    double read_pow[5]{};
    std::ifstream ifs("binary.txt", std::ios::in | std::ios::binary);
    if (ifs.is_open()) {
        ifs.read(reinterpret_cast<char*>(read_pow), sizeof(pow));
    }

    std::string_view sep;
    for (const auto& x: read_pow) {
        std::cout << std::exchange(sep, "; ") << x;
    }

    //------------------------------------------------------------------------------

    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::ofstream out2("matrix.bin", std::ios::binary);
    for (const auto& row : matrix) {
        out2.write(reinterpret_cast<const char*>(row.data()), row.size() * sizeof(int));
    }
    out.close();

    const int rows = 3;
    const int cols = 3;

    std::ifstream in("matrix.bin", std::ios::binary);
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        in.read(reinterpret_cast<char*>(matrix2[i].data()), cols * sizeof(int));
    }

    in.close();

    // Wyświetlenie
    for (const auto& row : matrix) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }

}
