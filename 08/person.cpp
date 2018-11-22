#include <iostream>

class Person
{
    public:
        Person(Person const&person) :
            idPerson(person.idPerson),
            name(person.name),
            sex(person.sex),
            birthday(person.birthday),
            homeAddress(person.homeAddress)
        {
        }

        Person(std::string id, std::string na, std::string se, std::string bi, std::string ha) :
            idPerson(id),
            name(na),
            sex(se),
            birthday(bi),
            homeAddress(ha)
        {
        }

        void O() const
        {
            std::cout << idPerson << ' ' << name << ' ' << sex << ' ' << birthday << ' ' << homeAddress;
        }

    private:
        std::string idPerson;
        std::string name;
        std::string sex;
        std::string birthday;
        std::string homeAddress;
};

int main()
{
    std::string id, na, se, bi, ha;
    std::cin >> id >> na >> se >> bi >> ha;
    Person(id, na, se, bi, ha).O();
    return 0;
}
