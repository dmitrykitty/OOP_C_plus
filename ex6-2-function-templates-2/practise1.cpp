#include <iostream>

class ValueError : std::exception {
    std::string msg;
public:
    ValueError(const char* msg) : msg(msg) {}
    ValueError(const ValueError&) = default; 
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class Window {
    int width;
    int height;
public:
    Window(int width, int height) {
        if (width <= 0 || height <= 0) 
            throw ValueError("The value must be positive");
        this->width = width;
        this->height = height;
    }
    
    void get_data(int& w, int& h) const {
        w = width;
        h = height;
    }
};

class Rect {
    double width;
    double height;
public:
    Rect(double width, double height) {
        if (width <= 0 || height <= 0) 
            throw ValueError("The value must be positive");
        this->width = width;
        this->height = height;
    }
    void get_data(double& w, double& h) const {
        w = width;
        h = height;
    }
};

template <typename T1, typename T2 = int>
T2 get_square(const T1& obj){
    T2 x, y;
    obj.get_data(x,y);
    return x * y;
}

int main()
{
    try {
        Window w(100, -5);
        auto res_sq = get_square(w);
    } catch (const ValueError& e) {
        std::cout << "Window constructor: " << e.what() << std::endl;
    }

    return 0;
}