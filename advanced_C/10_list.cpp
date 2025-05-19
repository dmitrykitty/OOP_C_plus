template<typename T>
class List {
    struct BaseNode {
        //dla fake node, ktora bédzie będzie następna
        //dla ostatniej nody i następna dla pierwszej
        BaseNode* prev;
        BaseNode* next;
    };

    struct Node : BaseNode {
        T value;

        Node(BaseNode* prev, BaseNode* next, const T& val): BaseNode(prev, next), value(val){}
    };

    BaseNode fakeNode;
    //fakeNode.next = begin()
    //fakeNode.prev = end()
    size_t sz{};

public:
    List(): fakeNode{&fakeNode, &fakeNode}, sz(0) {}
    //jak lista jest pusta, fakeNode ma wskazniki na samą siebie
    //fake node jest potrzebna aby --end() dało ostani element

    void push_back(const T& val) {
        BaseNode* prev = fakeNode.prev;
        BaseNode* next = &fakeNode;

        Node* node = new Node(prev, next, val);
        prev->next = node;
        next->prev = node;

        sz++;
    }

    void push_front(const T& val) {
        BaseNode* prev = &fakeNode;
        BaseNode* next = fakeNode.next;

        Node* node = new Node(prev, next, val);
        prev->next = node;
        next->pref = node;

        sz++;
    }

    ~List() {
        BaseNode* cur = fakeNode.next;
        while (cur != &fakeNode) {
            BaseNode* to_delete = cur;
            cur = cur->next;
            delete static_cast<Node*>(to_delete);
        }
    }
};

//metody
/*
lst.sort() - mergesort

lst.merge() - łączy dwa posortowane listy

lst.splice() - wycina kawałek z jednej listy i wstawia do innej
działa za O(n) jezeli dwie rozne listy(bo trzeba zwiększyc size)
a jak ta sama lista O(1)



*/


int main() {}
