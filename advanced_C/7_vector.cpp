template <typename T>
class vector {
    T* arr_;
    size_t size_;
    size_t capacity_;

    void reserve(size_t new_capacity) {
        //T* new_arr = new T[new_capacity]; problem - nie trzeba wywoływac konstruktory klas złożonych
        //a jak nie ma konstruktora domyślnego u T?
        //allocatory działają akurat w taki sposob

        T* new_arr = reinterpret_cast<T*>(new char[new_capacity * sizeof(T)]);
        for (size_t i = 0; i < size_; ++i) {
            new_arr[i] = arr_[i]; //
        }
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ > 0 ? capacity_ * 2 : 1);
        }
    }
};

int main() {
    return 0;
}
