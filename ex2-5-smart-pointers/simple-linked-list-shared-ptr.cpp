#include <iostream>
#include <memory>

struct object {
    int data;
    std::shared_ptr<object> next;
    object(int data) : data(data) {}
};

using shared_obj_ptr = std::shared_ptr<object>;

void push_back(shared_obj_ptr &head, shared_obj_ptr &tail, int data) {
    if (head == nullptr) {
        head = std::make_shared<object>(data);
        tail = head;
        return;
    }
    shared_obj_ptr curr_tail{tail};
    tail = std::make_shared<object>(data);
    curr_tail->next = tail;
}

void pop_front(shared_obj_ptr &head, shared_obj_ptr &tail) {
    if (head == nullptr)
        return;
    if (head == tail) {
        head.reset();
        return;
    }
    shared_obj_ptr new_head = head->next;
    head = new_head;
}

void show(const shared_obj_ptr &head) {
    shared_obj_ptr curr{head};
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    shared_obj_ptr head, tail;
    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);

    show(head);
    return 0;
}
