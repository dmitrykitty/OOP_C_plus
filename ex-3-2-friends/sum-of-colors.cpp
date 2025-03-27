#include <iostream>
using uch = unsigned char;

class ColorRGB {
    uch r{0}, g{0}, b{0};
public:
    ColorRGB(uch r=0, uch g=0, uch b=0): r(r), g(g), b(b){ }
    unsigned get_color() const { return r + g*256 + b*65536; }

    friend ColorRGB operator+(const ColorRGB& left, const ColorRGB& right);
};
ColorRGB operator+(const ColorRGB& left, const ColorRGB& right){
    uch new_r = left.r + right.r > 255 ? 255 : left.r + right.r;
    uch new_g = left.g + right.g > 255 ? 255 : left.g + right.g;
    uch new_b = left.b + right.b > 255 ? 255 : left.b + right.b;
    return {new_r, new_g, new_b};
}

int main(){
  ColorRGB color1(100, 100, 100), color2(255, 0, 80);
  ColorRGB color3 = color1 + color2;
  std::cout << color3.get_color() << std::endl;

  return 0;
}