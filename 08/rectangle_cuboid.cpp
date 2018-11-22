#include <iostream>

template<typename Arithmetic>
class Rectangle
{
    public:
        void set(Arithmetic length, Arithmetic width);
        Arithmetic area() const;
    private:
        Arithmetic _length;
        Arithmetic _width;
};

template<typename Arithmetic>
class Cuboid : private Rectangle<Arithmetic>
{
    public:
        void set(Arithmetic length, Arithmetic width, Arithmetic height);
        Arithmetic volume() const;
    private:
        Arithmetic _height;
};

template<typename Arithmetic, typename FormattedInputStream>
FormattedInputStream& operator>>(FormattedInputStream& in, Cuboid<Arithmetic>& cuboid)
{
    Arithmetic length, width, height;
    in >> length >> width >> height;
    cuboid.set(length, width, height);
    return in;
}

template<typename Arithmetic, typename FormattedInputStream>
FormattedInputStream& operator>>(FormattedInputStream& in, Rectangle<Arithmetic>& rectangle)
{
    Arithmetic length, width;
    in >> length >> width;
    rectangle.set(length, width);
    return in;
}

int main()
{
    Rectangle<int> rectangle;
    Cuboid<int> cuboid;

    std::cin  >> rectangle >> cuboid;

    std::cout << rectangle.area() << ' ' << cuboid.volume();

    return 0;
}

template<typename Arithmetic>
void Rectangle<Arithmetic>::set(Arithmetic length, Arithmetic width)
{
    _length = length;
    _width  = width;
}

template<typename Arithmetic>
Arithmetic Rectangle<Arithmetic>::area() const
{
    return _length * _width;
}

template<typename Arithmetic>
void Cuboid<Arithmetic>::set(Arithmetic length, Arithmetic width, Arithmetic height)
{
    Rectangle<Arithmetic>::set(length, width);
    _height = height;
}

template<typename Arithmetic>
Arithmetic Cuboid<Arithmetic>::volume() const
{
    return _height * Rectangle<Arithmetic>::area();
}
