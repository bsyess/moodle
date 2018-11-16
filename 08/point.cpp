#include <algorithm>
#include <iostream>

class Point
{
        friend int calcH(Point const&, Point const&);
        friend int calcV(Point const&, Point const&);
    private:
        int x, y;
    public:
        Point(int i = 0, int j = 0) : x(i), y(j) {}
        Point& operator-=(Point const&);
        std::istream& read(std::istream&);
};

std::istream& Point::read(std::istream& in)
{
    return in >> x >> y;
}

std::istream& operator>>(std::istream& in, Point& p)
{
    return p.read(in);
}

Point& Point::operator-=(Point const& p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

Point operator-(Point p, Point const& q)
{
    return p -= q;
}

int calcH(Point const& p, Point const& q)
{
    return std::abs((p - q).x);
}

int calcV(Point const& p, Point const& q)
{
    return std::abs((p - q).y);
}

int main()
{
    Point x, y;
    std::cin >> x >> y;
    std::cout << calcH(x, y) << ' ' << calcV(x, y);
}
