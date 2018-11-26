#include <cmath>
#include <iostream>

template<typename Arithmetic>
class Rectangle
{
    public:
        void set(Arithmetic height, Arithmetic width);
        Arithmetic area() const;
        Arithmetic perimeter() const;
    private:
        Arithmetic _height;
        Arithmetic _width;
};

template<typename Arithmetic, typename FormattedInputStream>
FormattedInputStream& operator>>(FormattedInputStream& in, Rectangle<Arithmetic>& rectangle)
{
    Arithmetic x0, y0, x1, y1;
    in >> x0 >> y0 >> x1 >> y1;
    rectangle.set(std::abs(x1 - x0), std::abs(y1 - y0));
    return in;
}

int main()
{
    Rectangle<int> rectangle;

    std::cin  >> rectangle;

    std::cout << rectangle.perimeter() << ' ';
    std::cout << rectangle.area();

    return 0;
}

template<typename Arithmetic>
void Rectangle<Arithmetic>::set(Arithmetic height, Arithmetic width)
{
    _height = height;
    _width  = width;
}

template<typename Arithmetic>
Arithmetic Rectangle<Arithmetic>::area() const
{
    return _height * _width;
}

template<typename Arithmetic>
Arithmetic Rectangle<Arithmetic>::perimeter() const
{
    return 2 * (_height + _width);
}
