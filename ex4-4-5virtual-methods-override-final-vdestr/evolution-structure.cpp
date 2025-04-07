#include <iostream>

enum type_life {
    lf_protists = 1,
    lf_plants = 2,
    lf_animals = 3,
    lf_mosses = 4,
    lf_flowering = 5,
    lf_worms = 6,
    lf_mammals = 7,
    lf_human = 8,
    lf_monkeys = 9
};

class Protists {
    const type_life type{lf_protists};

public:
    virtual const type_life get_type() const { return type; }

    virtual ~Protists() = default;
};

class Plants : public Protists {
    const type_life type{lf_plants};

public:
    const type_life get_type() const override { return type; }
};

class Mosses : public Plants {
    const type_life type{lf_mosses};

public:
    const type_life get_type() const override { return type; }
};

class Flowering : public Plants {
    const type_life type{lf_flowering};

public:
    const type_life get_type() const override { return type; }
};

class Animals : public Protists {
    const type_life type{lf_animals};

public:
    const type_life get_type() const override { return type; }
};

class Worms : public Animals {
    const type_life type{lf_worms};

public:
    const type_life get_type() const override { return type; }
};

class Mammals : public Animals {
    const type_life type{lf_mammals};

public:
    const type_life get_type() const override { return type; }
};

class Human : public Mammals {
    const type_life type{lf_human};

public:
    const type_life get_type() const override { return type; }
};

class Monkeys : public Mammals {
    const type_life type{lf_monkeys};

public:
    const type_life get_type() const override { return type; }
};

int main() {
    Protists *life[] = {
        new Plants(), new Flowering(), new Flowering(), new Monkeys(),
        new Animals(), new Worms(), new Worms(), new Human(), new Monkeys(), new Mammals(), new Animals(), new Animals()
    };

    size_t sz_an {0}, sz_mn {0};

    for(auto & i : life) {
        if(i->get_type() == lf_animals)
            sz_an++;

        if(i->get_type() == lf_monkeys)
            sz_mn++;
    }

    auto** lf_lst1 = new Animals*[sz_an];
    auto** lf_lst2 = new Monkeys*[sz_mn];

    int count1 {0}, count2 {0};
    for(auto & i : life) {
        if(i->get_type() == lf_animals)
            lf_lst1[count1++] = dynamic_cast<Animals *>(i);

        if(i->get_type() == lf_monkeys)
            lf_lst2[count2++] = dynamic_cast<Monkeys *>(i);
    }

    delete[] lf_lst1;
    delete[] lf_lst2;
}
