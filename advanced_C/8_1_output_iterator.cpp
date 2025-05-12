#include <iostream>
#include <algorithm>
#include <vector>

bool even(int x) {
    return x % 2 == 0;
}

//output iterator
//std::back_insert_iterator
//

template<typename Container>
class back_insert_iterator {
    Container& container_;

public:
    explicit back_insert_iterator(Container& container_) : container_(container_) {}

    back_insert_iterator& operator=(const typename Container::value_type& value) {
        container_.push_back(value);
        return *this;
    }

    back_insert_iterator& operator*() { return *this; }
    back_insert_iterator& operator++() { return *this; }
    back_insert_iterator& operator++(int) { return *this; }
};

/*
*it1++ = *it2++;
this* = this*
container_.push_back(our container type) - dodajemy kolejny block

 */

template<typename Container>
back_insert_iterator<Container> back_inserter(Container& container) {
    //back_inserter - funkcja tworząca back_insert_operator
    return {container};
}

int main() {
    int a[10] = {1, 2, 3, 4, 5};
    std::vector<int> v;

    //w taki sposob będzie ub, bo od pewnego momentu alo będzie pisac poza vectorem
    std::copy_if(a, a + 10,
                 std::back_insert_iterator<std::vector<int> >(v), &even);
    //a mozna napisac w taki sposob back_inserter(v)
    //jesy rowniez front_inserter oraz inserter
    //pozwala na dokładanie elementow
    return 0;
}
