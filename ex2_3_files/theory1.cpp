#include <fstream>
#include <iostream>

int main() {
    //ifstream - czytanie z pliku
    //ofstream - zapis
    //fstream - to i to

    std::ofstream ofs;
    std::ifstream ifs("read_text.txt", std::ios::app | std::ios::binary); //otwieramy pl8ik na dozapisywanie w
    //trybie binary

    ofs.open("text.txt"); //tworzy sie nowy plik
    //mozna rowniez std::ofstream ofs("...");

    std::cout << ifs.is_open() << " " << ofs.is_open() << std::endl; //0 1, bo ofs stworzył file, ifs nie

    /*
     * Tryby otwierania pliku (można je łączyć za pomocą | ):
     * std::ios::in      – odczyt (ifstream, fstream)
        std::ifstream file("mode_demo.txt", std::ios::in);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << "READ: " << line << "\n";
        }

     * std::ios::out     – zapis (ofstream, fstream); UWAGA: usuwa zawartość pliku!
        std::ofstream file("mode_demo.txt", std::ios::out);
        file << "Line A (out)\n"; // Całkowicie nadpisuje plik

     * std::ios::app     – dopisywanie na końcu pliku (append)
        std::ofstream file("mode_demo.txt", std::ios::app);
        file << "Line B (app)\n"; // Dopisuje na końcu pliku

     * std::ios::ate     – otwiera plik i ustawia wskaźnik na końcu, ale można pisać/odczytywać w dowolnym miejscu
         std::ofstream file("mode_demo.txt", std::ios::ate);
         file << "Line C (ate)\n"; // Pisze na końcu pliku jak `app`, ALE...
         file.seekp(0);            // można przeskoczyć np. na początek
         file << "START->";        // nadpisze początek!

     * std::ios::binary  – tryb binarny (domyślnie pliki są otwierane jako tekstowe)

     std::fstream file("mode_demo.txt", std::ios::in | std::ios::out);
     std::string word;
     file >> word;          // czyta pierwszy wyraz z pliku
     file.seekp(0);         // wraca na początek
     file << "MODIFIED ";   // nadpisuje pierwsze słowo
     file.close();*/

    /*
    seekg(offset, std::ios::beg);  // od początku pliku (get), to samo dla seekp(put)
    seekg(offset, std::ios::cur);  // od bieżącej pozycji
    seekg(offset, std::ios::end);  // od końca pliku

    tellg(), tellp() - zwraca aktualną pozycje wskaznika
    */

    ofs.close();
    ifs.close();

    std::ofstream ofs2("test.txt");
    if (ofs2.is_open()) {
        ofs2 << 10 << " " << -5.345 << " " << -34 << std::endl;
        //zapisywanie od test.txt
        ofs2 << "Krystina, do you wanna marry me" << std::endl;
        ofs2 << "Yes, I do" << std::endl;
    }

    ofs2.close();
    int a, b;
    double c;
    std::string str;
    std::ifstream ifs2("test.txt");
    if (ifs2.is_open()) {
        ifs2 >> a >> c >> b;
        while (str.empty() && !ifs2.eof())
            std::getline(ifs2, str);
    }
    ifs2.close();
    std::cout << a << b << c << std::endl;
    std::cout << str;


    return 0;
}
