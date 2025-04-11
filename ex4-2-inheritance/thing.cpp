#include <iostream>
#include <string>
#include <utility>

class Thing {
protected:
    std::string name;
    int price{0};

public:
    Thing(std::string name, int price) : name(std::move(name)), price(price) {}

    void set_base_info(const std::string &name, int &price) {
        this->name = name;
        this->price = price;
    }

    void get_base_info(std::string &name, int &price) const {
        name = this->name;
        price = this->price;
    }
};

class TV : public Thing {
    int size{};
    double weight{};

public:
    TV(std::string name, int price, int size, double weight): Thing(std::move(name), price), size(size),
                                                              weight(weight) {}

    void get_data(std::string &name, int &price, int &size, double &weight) const {
        name = this->name;
        price = this->price;
        weight = this->weight;
        size = this->size;
    }
};

class Book : public Thing {
    std::string author;
    int pages{};

public:
    Book(std::string name, int price, std::string author, int pages): Thing(std::move(name), price),
                                                                      author(std::move(author)), pages(pages) {}

    void get_data(std::string &name, int &price, std::string &author, int &pages) const {
        name = this->name;
        price = this->price;
        author = this->author;
        pages = this->pages;
    }
};

class Store {
    enum { max_total = 100 };

    Thing *things[max_total]{nullptr};
    int total{};

public:
    void append(Thing *th) {
        if (total < max_total)
            things[total++] = th;
    }

    Thing *operator[](int index) const {
        if (index < 0 && index >= total)
            return nullptr;

        return things[index];
    }

    int get_total() const { return total; }

    ~Store() {
        for (int i = 0; i < total; i++)
            delete things[i];
    }
};


int main() {
    Store st;
    st.append(new TV("Samsung", 54300, 43, 5.4));
    st.append(new Book("C++", 2000, "Balakirev", 543));
    st.append(new TV("Sony", 97000, 80, 7.5));

    return 0;
}
