#include <iostream>
#include <string>

void get_line(char* buff, size_t max_buff) {
    std::string line;
    getline(std::cin, line);

    int i = 0;
    for (; i < line.length() && i < max_buff - 1; ++i)
        buff[i] = line[i];
    buff[i] = '\0';
}

int main() {
    char str[100];
    //  get_line(str, sizeof(str));

    auto gl = [&]() {
        std::string line;
        getline(std::cin, line);

        int i = 0;
        for (; i < line.length() && i < sizeof(str) - 1; ++i)
            str[i] = line[i];
        str[i] = '\0';
    };
    gl();
    puts(str);

    return 0;
}
