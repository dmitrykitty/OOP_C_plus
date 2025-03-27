#include <iostream>

enum type_memory {mem_none = -1, mem_corsair = 1, mem_adata = 2, mem_kingston = 3};

class Memory {
    type_memory type {mem_none}; // тип (производитель) ОЗУ
    unsigned volume; // объем ОЗУ в Мб
public:
    Memory(unsigned vol=0, type_memory mem=mem_none): volume(vol), type(mem){}
    
    friend void set_memory_data(Memory& mem, unsigned vol, type_memory tp); 
    friend void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp);
    friend Memory operator+(const Memory& left, const Memory& right); 
};

void set_memory_data(Memory& mem, unsigned vol, type_memory tp){
    mem.volume = vol; 
    mem.type = tp;
}
void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp){
    vol = mem.volume; 
    tp = mem.type; 
}
Memory operator+(const Memory& left, const Memory& right){
    if(left.type != right.type)
        return left; 
    else
        return {left.volume + right.volume, left.type};
}
int main(void)
{
    Memory mem_1(8000, mem_adata), mem_2(4000, mem_adata);
    Memory res = mem_1 + mem_2; 


    return 0;
}