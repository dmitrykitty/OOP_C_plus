#include <iostream>

enum type_filter_water {
    flt_none = 0,
    flt_mechanical = 1,
    flt_aragon = 2,
    flt_calcium = 3
};

class FilterWater {
protected:
    unsigned date{0};
    type_filter_water type{flt_none};

public:
    FilterWater(type_filter_water tp = flt_none, unsigned date = 0): type(tp), date(date) {}
    unsigned get_date() const { return date; }
    type_filter_water get_type() const { return type; }
};

class Mechanical : public FilterWater {
public:
    Mechanical(unsigned date): FilterWater(flt_mechanical, date) {}
};

class Aragon : public FilterWater {
public:
    Aragon(unsigned date): FilterWater(flt_aragon, date) {}
};

class Calcium : public FilterWater {
public:
    Calcium(unsigned date): FilterWater(flt_calcium, date) {}
};

class GeyserClassic {
public:
    enum { total_slots = 3 };

private:
    FilterWater *slots[total_slots]{nullptr};

public:
    GeyserClassic(FilterWater *f1 = nullptr, FilterWater *f2 = nullptr, FilterWater *f3 = nullptr) {
        add_filter(1, f1);
        add_filter(2, f2);
        add_filter(3, f3);
    }

    const FilterWater *operator[](int index) const;

    void add_filter(int slot_num, FilterWater *filter);
};


const FilterWater *GeyserClassic::operator[](int index) const {
    if (index < 0 || index >= total_slots || slots[index] == nullptr)
        return nullptr;
    return slots[index];
}

void GeyserClassic::add_filter(int slot_num, FilterWater *filter) {
    if (!slots[slot_num - 1] && static_cast<type_filter_water>(slot_num) == filter->get_type())
        slots[slot_num - 1] = filter;
}

int main() {
    Mechanical filter_1(100);
    Aragon filter_2(100);
    Calcium filter_3(100);

    GeyserClassic gc_1;
    GeyserClassic gc_2(&filter_1);
    GeyserClassic gc_3(&filter_1, &filter_2);
    GeyserClassic gc_4(&filter_1, &filter_2, &filter_3);

    return 0;
}

