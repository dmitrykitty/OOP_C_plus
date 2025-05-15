#include <iterator>

//distancew O(n) dla set, map, ale O(1) dla vector, array
//podobnie działa advance
template<typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance(Iterator first, Iterator last) {
    if constexpr (std::is_base_of_v<
        std::random_access_iterator_tag,
        typename std::iterator_traits<Iterator>::iterator_category
    >) {
        return last - first;
    }
    int i = 0;
    for (; first != last; ++first, ++i) {
        //empty body
    }
    return i;
}

//pomocnicze funcje std::prev oraz std:next

int main() {}
