#include <iostream>

class DataThree {
    DataThree() = default;
    static int counter;
    static DataThree* obj_ptr;
public:
    static DataThree* get_new_data(){
        if(counter < 3){
            obj_ptr = new DataThree();
            counter++;
            return obj_ptr;
        }
        return obj_ptr;
    }

    static int get_counter(){ return counter; }

    ~DataThree(){
        delete obj_ptr;
        counter--;
    }
};

int DataThree::counter = 0;
DataThree* DataThree::obj_ptr = nullptr;

int main()
{
    DataThree* ptr_dates[5];
    for(int i = 0; i < 5; i++) {
        ptr_dates[i] = DataThree::get_new_data();
        std::cout << ptr_dates[i] << ": " << DataThree::get_counter() << std::endl;
    }

    return 0;
}