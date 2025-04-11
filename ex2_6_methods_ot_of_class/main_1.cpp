#include <iostream>

class Wallet {
    int volume{0}; 
    bool check_volume(int x);
        
public: 
    Wallet(int w): volume(w){ }
    
    void add(int vol);
    int get_volume();
    
};

bool Wallet::check_volume(int x){
    return x >= 0 ? true : false;
}

void Wallet::add(int vol){
    if(check_volume(vol))
        volume += vol;
}

int Wallet::get_volume(){ return volume; }

int main()
{
    Wallet wallet(544653);
    int vl = wallet.get_volume();
    std::cout << vl << std::endl;
    wallet.add(-600);
    vl = wallet.get_volume();
    std::cout << vl << std::endl;

    return 0;
}