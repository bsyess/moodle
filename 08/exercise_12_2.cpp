#include <cstring>
#include <iostream>

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length () const { return len; }
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);
    static int HowMany();

    String operator+(String const& st) const;
    String const& stringlow();
    String const& stringup();
    int has(char c) const;
};

String String::operator+(String const& st) const
{
    char* s = new char[std::strlen(str) + std::strlen(st.str) + 1];
    std::strcpy(s, str);
    std::strcat(s, st.str);
    return s;
}

String operator+(char const* s, String const& st)
{
    return String(s) + st;
}

String const& String::stringlow()
{
    for (char* s = str; *s; ++s)
        *s = std::tolower(*s);
    return *this;
}

String const& String::stringup()
{
    String st(*this);
    for (char* s = str; *s; ++s)
        *s = std::toupper(*s);
    return *this;
}

int String::has(char c) const
{
    int count = 0;
    for (char const* s = str; *s; ++s)
        if (*s == c)
            ++count;
    return count;
}

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name:\n";
    String s3;
    std::cout << s2; 
    std::cin >> s3; 
    s2 = "My name is " + s3; 
    std::cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); 
    std::cout << "The string " << s2 << "\ncontains " << s2.has('A')
    << " 'A' characters in it.\n";
    s1 = "red"; 
    String rgb[3] = { String(s1), String("green"), String("blue")};
    std::cout << "Enter the name of a primary color for mixing light:\n";
    String ans;
    bool success = false;
    while (true)
    {
        std::cin >> ans;
        ans.stringlow(); 
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) 
            {
                success = true;
                break;
            }
        }
        if (success)
        {
            std::cout << "That's right!\n";
            break;
        }
        else
            std::cout << "Try again!\n";
    }
    std::cout << "Bye\n";
    return 0;
}

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM, '\r');
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
