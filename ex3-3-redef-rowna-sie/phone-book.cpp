#include <iostream>
#include <string>

struct PhoneBookItem {
    std::string fio; // ФИО контакта
    std::string phone_number; // номер телефона

    PhoneBookItem() = default;
    PhoneBookItem(std::string fio, std::string phone_number)
        : fio(fio), phone_number(phone_number){ }
};

class PhoneBook {
    enum { max_phone_book = 100 }; // максимальная емкость телефонной книжки
    PhoneBookItem* phone_book {nullptr}; // массив из записей
    size_t count {0}; // количество записей в телефонной книжке
public:
    PhoneBook(){ phone_book = new PhoneBookItem[max_phone_book]; }
    PhoneBook(PhoneBookItem* lst, size_t size){
        count = (size > max_phone_book) ? max_phone_book : size;

        phone_book = new PhoneBookItem[max_phone_book];
        for(int i = 0;i < count; ++i)
            phone_book[i] = lst[i];
    }
    PhoneBook(const PhoneBook& other): PhoneBook(other.phone_book, other.count) { }

    const PhoneBookItem* get_phone_book()const { return phone_book; }
    size_t get_count()const { return count; }

    bool append(const PhoneBookItem& item);
    PhoneBook operator+(const PhoneBookItem& it);
    PhoneBook& operator=(const PhoneBook& other);


    ~PhoneBook() { delete[] phone_book; }
};

bool PhoneBook::append(const PhoneBookItem& item){
    if(count >= max_phone_book)
        return false;
    phone_book[count++] = item;
    return true;
}

PhoneBook PhoneBook::operator+(const PhoneBookItem& it){
    PhoneBook new_book = *this;
    if(count < max_phone_book)
        new_book.phone_book[new_book.count++] = it;
    return new_book;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other){
    if(this == &other) return *this;

    delete[] phone_book;
    count = other.count;
    phone_book = new PhoneBookItem[count];

    for(int i =0; i < count; i++)
        phone_book[i] = other.phone_book[i];

    return *this;
}


int main()
{
    auto* lst_item = new PhoneBookItem[4]{
        PhoneBookItem("А. Дзюба", "+71237694401"),
        PhoneBookItem("П. Гагарина", "+79234694105"),
        PhoneBookItem("О. Бузова", "+79041563055"),
        PhoneBookItem("Тимати", "+79121000000")
    };

    PhoneBook phone_lst(lst_item, 4);
    phone_lst.append({"Kristinka", "34464754634"});
    PhoneBookItem it = {"Dimka", "4784385893498"};
    phone_lst = phone_lst + it;

    for(int i = 0; i < phone_lst.get_count(); ++i)
        std::cout << phone_lst.get_phone_book()[i].fio << " " << phone_lst.get_phone_book()->phone_number << std::endl;

    auto* lst_item2 = new PhoneBookItem[4] {
        PhoneBookItem("А. Дзюба", "+71237694401"),
        PhoneBookItem("О. Бузова", "+79041563055")
    };
    std::cout << std::endl;
    PhoneBook phone_lst2(lst_item2, 2);
    phone_lst2 = phone_lst;
    for(int i = 0; i < phone_lst2.get_count(); ++i)
        std::cout << phone_lst2.get_phone_book()[i].fio << " " << phone_lst2.get_phone_book()->phone_number << std::endl;


    delete[] lst_item;
    delete[] lst_item2;

    return 0;
}