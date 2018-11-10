#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <stack>

typedef long double Float;
typedef unsigned long long Int;
typedef std::string String;

class Student
{
    friend class StudentManager;
public:
    Student(bool input = false);
    bool operator<(Student const&) const;
    void out() const;

private:
    Float  _score() const;

    Int    _id;
    Int    _class;
    String _name;
    Float  _score1;
    Float  _score2;
    Float  _score3;
};

class StudentManager
{
public:
    void input();
    void delete_();
    void select();
    void order();
    void output();
    void quit();
private:
    std::list<Student> _students;
};

StudentManager sm;

void (StudentManager::* mode[7])() =
{
    0,
    &StudentManager::input,
    &StudentManager::delete_,
    &StudentManager::select,
    &StudentManager::order,
    &StudentManager::output,
    &StudentManager::quit
};

int main()
{
    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(1);
    while (true)
    {
        Int t;
        std::cout << "1.input\n";
        std::cout << "2.delete\n";
        std::cout << "3.select\n";
        std::cout << "4.order\n";
        std::cout << "5.output\n";
        std::cout << "6.quit\n";
        std::cout << "please input your option\n";
        std::cin  >> t;
        (sm.*mode[t])();
    }
    return 0;
}

void StudentManager::input()
{
    std::string ifContinue;
    do
    {
        _students.push_back(Student(true));
        std::cout << "continue?\n";
        std::cin  >> ifContinue;
    } while (ifContinue == "yes");
}

void StudentManager::delete_()
{
    std::string data;
    do
    {
        std::cin >> data;
        std::list<Student>::iterator student = _students.begin();
        while (student != _students.end())
        {
            if (student->_id != std::atol(data.c_str()) && student->_name != data)
            {
                student->out();
                ++student;
            }
            else
            {
                std::list<Student>::iterator t = student++;
                _students.erase(t);
            }
        }
        std::cout << "continue?\n";
        std::cin  >> data;
    } while (data == "yes");
}

void StudentManager::select()
{
    bool ifContinue = false;
    do
    {
        Int data;
        std::cin >> data;
        bool found = false;
        std::list<Student>::const_iterator student = _students.begin();
        for (; student != _students.end(); ++student)
        {
            if (student->_id == data || student->_class == data)
            {
                student->out();
                found = true;
            }
        }
        if (found)
        {
            String strContinue;
            std::cout << "continue?\n";
            std::cin  >> strContinue;
            ifContinue = strContinue == "yes";
        }
        else
        {
            std::cout << "there is no eligible student\n";
        }
    } while (ifContinue);
}

void StudentManager::order()
{
    _students.sort();
    output();
}

void StudentManager::output()
{
    std::list<Student>::const_iterator student = _students.begin();
    for (; student != _students.end(); ++student)
    {
        student->out();
    }
}

void StudentManager::quit()
{
    std::exit(EXIT_SUCCESS);
}

Student::Student(bool input)
{
    if (input)
    {
        std::cout << "Id ";
        std::cin  >> _id;
        std::cout << "class ";
        std::cin  >> _class;
        std::cout << "name ";
        std::cin  >> _name;
        std::cout << "score1 ";
        std::cin  >> _score1;
        std::cout << "score2 ";
        std::cin  >> _score2;
        std::cout << "score3 ";
        std::cin  >> _score3;
    }
}

bool Student::operator<(Student const& that) const
{
    if (_class != that._class)
    {
        return _class < that._class;
    }
    return _score() > that._score();
}

void Student::out() const
{
    std::cout << _id      << ',';
    std::cout << _class   << ',';
    std::cout << _name    << ',';
    std::cout << _score1  << ',';
    std::cout << _score2  << ',';
    std::cout << _score3  << ',';
    std::cout << _score() << '\n';
}

Float Student::_score() const
{
    return _score1 + _score2 + _score3;
}
