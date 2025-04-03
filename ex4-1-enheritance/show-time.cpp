#include <iostream>

class Clock{
protected:
    unsigned time_current{0};
public:
    Clock(unsigned tm=0): time_current(tm){ }
    void set_time(unsigned tm) { time_current = tm; }
    unsigned get_hours()const { return time_current / 3600; }
    unsigned get_minutes()const { return time_current / 60 % 60; }
    unsigned get_seconds()const { return time_current % 60; }
};

class ClockShow: public Clock {
public:
    enum time_format {
        tm_hhmmss = 1,
        tm_hms = 2,
        tm_ssmmhh = 3,
        tm_smh = 4
    };
private:
    time_format format {tm_hhmmss};
public:
    ClockShow(unsigned tm=0, time_format f=tm_hhmmss): Clock(tm), format(f) { }
    void show_time()const {
        switch(format){
            case tm_hhmmss:
                printf("%02d:%02d:%02d", get_hours(), get_minutes(), get_seconds());
            break;
            case tm_hms:
                printf("%d:%d:%d", get_hours(), get_minutes(), get_seconds());
            break;
            case tm_ssmmhh:
                printf("%02d:%02d:%02d", get_seconds(), get_minutes(), get_hours());
            break;
            case tm_smh:
                printf("%d:%d:%d", get_seconds(), get_minutes(), get_hours());
            break;
        }
    }
};



int main()
{
    unsigned tm;
    std::cin >> tm;



    return 0;
}