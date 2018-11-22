// #include <cmath>

#include <iostream>

long double const PI = 3.14; // std::acos(-1.0L)

template<typename Arithmetic>
class Circle
{
    public:
        explicit Circle(Arithmetic radius = 0) : _radius(radius) {}
        Circle(Circle const& circle) : _radius(circle._radius) {}
        Arithmetic area() const;
        Arithmetic radius() const;
        Arithmetic perimeter() const;
    private:
        Arithmetic _radius;
};

int main()
{
    long double radius;
    std::cin >> radius;
    Circle<long double> circle = Circle<long double>(radius);
    std::cout << circle.radius()    << ' ';
    std::cout << circle.perimeter() << ' ';
    std::cout << circle.area();
    return 0;
}

template<typename Arithmetic>
Arithmetic Circle<Arithmetic>::area() const
{
    return PI * _radius * _radius;
}

template<typename Arithmetic>
Arithmetic Circle<Arithmetic>::radius() const
{
    return _radius;
}

template<typename Arithmetic>
Arithmetic Circle<Arithmetic>::perimeter() const
{
    return 2 * PI * _radius;
}
