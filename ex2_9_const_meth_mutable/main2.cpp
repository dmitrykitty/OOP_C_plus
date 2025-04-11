#include <iostream>

class BoxDims {
    unsigned short dimension{0};
    unsigned* dims{nullptr};
public:
    BoxDims(unsigned size_1): dimension(1){
      dims = new unsigned[dimension];
      dims[0] = size_1;
     }
    BoxDims(unsigned size_1, unsigned size_2): BoxDims(size_1){
      dimension = 2;
      dims[1] = size_2;
     }
    BoxDims(unsigned size_1, unsigned size_2, unsigned size_3): BoxDims(size_1, size_2){
      dimension = 3;
      dims[2] = size_3;
     }
    BoxDims(unsigned* ds, unsigned size_ds): dimension(size_ds){
      dims = new unsigned[dimension];
      set_dims(ds);
    }

    void set_dims(unsigned* ds){
        for(int i = 0; i < dimension; i++)
            dims[i] = ds[i];
    }
    unsigned short get_dimension() const { return dimension; }
    const unsigned* get_dims() const { return dims; }
    unsigned get_volume() const {
        unsigned volume = 1;
        for(int i = 0; i < dimension; i++)
            volume *= dims[i];
        return volume;
    }

    ~BoxDims()
    {
        if (dims) delete [] dims;
    }
};




int main(void)
{
    BoxDims box(3, 10, 5);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}