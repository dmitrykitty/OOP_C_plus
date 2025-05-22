#include <iostream>

template<typename AR>
AR ar_sum_positive(const AR* ar, size_t sz) {
    AR sum = 0;
    for (int i = 0; i < sz; i++) {
        if (ar[i] > 0)
            sum += ar[i];
    }
    return sum;
}

int main() {
    float d1[] = {0.1f, 2.4f, 1.5f, -0.3f, 1.0f, -11.5f};
    double d2[] = {-4.3, 0.8, 15.3, -0.01, -1.2, -6.5};
    int d3[] = {6, 4, -1, -3, 0, 10, 8, -1, 2};

    float s1 = ar_sum_positive(d1, std::size(d1));
    double s2 = ar_sum_positive(d2, std::size(d2));
    int s3 = ar_sum_positive(d3, std::size(d3));

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
}
