#include <iostream>

class Move
{
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0) : x(a), y(b) {}
        void showmove() const;
        Move add(Move const& m) const;
        void reset(double a = 0, double b = 0);
};

template<typename FormattedInputStream>
FormattedInputStream& operator>>(FormattedInputStream& in, Move& move)
{
    double x, y;
    char sep;
    in >> x >> sep >> y;
    move.reset(x, y);
    return in;
}

void Move::showmove() const
{
    std::cout << x << ',' << y << '\n';
}

Move Move::add(Move const& m) const
{
    return Move(x + m.x, y + m.y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    Move a;
    a.showmove();

    Move b;
    std::cin >> b;
    b.showmove();

    a = a.add(b);
    a.showmove();

    b.reset();
    b.showmove();
}
