#include <iostream>
#include <vector>

class Animal
{
    public:
        Animal(std::string const& name) : _name(name), _value(1)
        {
        }
        bool operator()(std::string const& name)
        {
            if (_name == name)
            {
                ++_value;
                return true;
            }
            else
            {
                return false;
            }
        }
        void operator()(size_t& value) const
        {
            if (_value > value)
            {
                value = _value;
            }
        }
        void operator[](size_t value) const
        {
            if (_value == value)
            {
                std::cout << _name << ' ' << _value << std::endl;
            }
        }
    private:
        std::string _name;
        size_t _value;
};

int main()
{
    size_t N;
    std::cin >> N;
    std::vector<Animal> animals;
    while (N--)
    {
        std::string name;
        std::cin >> name;
        bool found = false;
        for (size_t i = 0; i < animals.size(); ++i)
        {
            if (animals[i](name))
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            animals.push_back(name);
        }
    }
    size_t value = 0;
    for (size_t i = 0; i < animals.size(); ++i)
    {
        animals[i](value);
    }
    for (size_t i = 0; i < animals.size(); ++i)
    {
        animals[i][value];
    }
    return 0;
}
