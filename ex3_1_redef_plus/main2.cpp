class Wallet
{
    int volume {0};
public:
    Wallet(int v = 0) : volume(v)
    { }
    int operator + (const Wallet& right) const
    {
        return this->volume + right.volume;
    }
};

Wallet w1 {100}, w2 {200};
int val_2 = w1 + 300;

Wallet res_3 = 1000 + 500;

Wallet res_1 = w1 + w2;

int val_3 = 300 + w2;

int val_1 = w1 + w2;

Wallet res_2 = w1 + 500;

Wallet res_4 = 1000 + w2;