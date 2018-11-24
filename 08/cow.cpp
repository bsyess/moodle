#include <cstring>
#include <iostream>

class Cow
{
private:
    char name[20];
    char* hobby;
    double weight;
public:
    Cow();
    Cow(char const* nm, char const* ho, double wt);
    Cow(Cow const& c);
    ~Cow();
    Cow& operator=(Cow const& c);
    void ShowCow() const; // display all cow data
} original[2], clone1;

int main()
{
    std::string name, hobby1, hobby2;
    double weight;
    for (int i = 0; i < 2; ++i)
    {
        std::cin >> name >> hobby1 >> hobby2 >> weight;
        original[i] = Cow(name.data(), (hobby1 + ' ' + hobby2).data(), weight);
    }
    Cow const clone0(original[0]);
    clone0.ShowCow();
    clone1 = original[1];
    clone1.ShowCow();
    return 0;
}

Cow::Cow() : hobby(0), weight(0)
{
    std::strcpy(name, "");
}

Cow::Cow(char const* nm, char const* ho, double wt) :
    hobby(new char[std::strlen(ho) + 1]), weight(wt)
{
    std::strcpy(name, nm);
    std::strcpy(hobby, ho);
}

Cow::Cow(Cow const& c) :
    hobby(new char[std::strlen(c.hobby) + 1]), weight(c.weight)
{
    std::strcpy(name, c.name);
    std::strcpy(hobby, c.hobby);
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow& Cow::operator=(Cow const& c)
{
    std::strcpy(name, c.name);
    weight = c.weight;

    // "Effective C++" by Scott Meyers
    char* originalHobby = hobby;
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    delete[] originalHobby;

    return *this;
}

void Cow::ShowCow() const
{
    std::cout << name << ' ' << hobby << ' ' << weight << '\n';
}
