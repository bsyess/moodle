#include <iostream>

typedef long double Float;
typedef long long Int;

class Time
{
public:
    Time(Int h = 0, Int m = 0);
    void AddMin(Int m);
    void AddHr(Int h);
    void Reset(Int h = 0, Int m = 0);
    friend Time operator+(Time t, Time const& u);
    friend Time operator-(Time t, Time const& u);
    friend Time operator*(Time t, Float mult);
    friend Time operator*(Float mult, Time const& t);
    friend std::ostream& operator<<(std::ostream& os, Time const& t);
private:
    Int hours;
    Int minutes;
};

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    std::cout << "Aida and Tosca:\n";
    std::cout << aida<<"; " << tosca << std::endl;
    temp = aida + tosca;     // operator+()
    std::cout << "Aida + Tosca: " << temp << std::endl;
    temp = aida* 1.17;  // member operator*()
    std::cout << "Aida * 1.17: " << temp << std::endl;
    std::cout << "10.0 * Tosca: " << 10.0 * tosca << std::endl;
	// std::cin.get();
    return 0;
}

Time::Time(Int h, Int m) : hours(h), minutes(m) {}


void Time::AddMin(Int m)
{
    hours += (minutes += m) / 60;
    minutes %= 60;
}

void Time::AddHr(Int h)
{
    hours += h;
}

void Time::Reset(Int h, Int m)
{
    hours = h;
    minutes = m;
}

Time operator+(Time t, Time const& u)
{
    t.AddMin(u.minutes);
    t.AddHr(u.hours);
    return t;
}

Time operator-(Time t, Time const& u)
{
    t.AddMin(-u.minutes);
    t.AddHr(-u.hours);
    return t;
}

Time operator*(Time t, Float mult)
{
    Int totalminutes = (t.hours * 60 + t.minutes) * (mult - 1);
    t.AddMin(totalminutes);
    return t;
}

Time operator*(Float mult, Time const& t)
{
    return t * mult;
}

std::ostream& operator<<(std::ostream& os, Time const& t)
{
    return os << t.hours << " hours, " << t.minutes << " minutes";
}
