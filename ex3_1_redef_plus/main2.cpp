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
