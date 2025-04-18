#include <iostream>
#include <memory>

struct object {
private:
    short data;
    object *next;

public:
    object(short d, object *next = nullptr): data(d), next(next) {}

    object *get_next() const { return next; }
    short get_data() const { return data; }

    void set_next(object *ptr) { next = ptr; }
    void set_data(short d) { data = d; }
};


using st_unique_ptr = std::unique_ptr<object>;

void push(st_unique_ptr &top, short data) {
    if (top == nullptr) {
        top = std::make_unique<object>(data);
        return;
    }
    object *next_ptr = top.release();
    top = std::make_unique<object>(data, next_ptr);
}

int main() {
    st_unique_ptr top;

    for (int i = 1; i <= 7; ++i)
        push(top, i);


    object *top_ptr = top.get();

    while (top_ptr) {
        std::cout << top_ptr->get_data() << std::endl;
        top_ptr = top_ptr->get_next();
    }


    return 0;
};
