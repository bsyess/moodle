#include <iomanip>
#include <iostream>
#include <sstream>

std::string id[3] = {"10001", "10002", "10003"};
int cl[3] = {11, 12, 11};
std::string na[3] = {"Zhang", "Yang", "Liang"};
long double g1[3] = {99.5, 77.9, 92.5};
long double g2[3] = {88.5, 56.5, 99.0};
long double g3[3] = {89.5, 87.5, 60.5};

int main()
{
    std::stringstream s;
    std::string name;
    bool del = false;

    for (int i = 2; i; --i)
        for (int j = 0; j < i; ++j)
            if (cl[j] == cl[j + 1] && g1[j] + g2[j] + g3[j] < g1[j + 1] + g2[j + 1] + g3[j + 1] || cl[j] > cl[j + 1])
            {
                std::string sT;
                int iT;
                long double fT;

                sT = id[j], id[j] = id[j + 1], id[j + 1] = sT;
                iT = cl[j], cl[j] = cl[j + 1], cl[j + 1] = iT;
                sT = na[j], na[j] = na[j + 1], na[j + 1] = sT;
                fT = g1[j], g1[j] = g1[j + 1], g1[j + 1] = fT;
                fT = g2[j], g2[j] = g2[j + 1], g2[j + 1] = fT;
                fT = g3[j], g3[j] = g3[j + 1], g3[j + 1] = fT;
            }

    s << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    for (int i = 0; i < 3; ++i)
        s << id[i] << ' ' << cl[i] << ' ' << na[i] << ' ' << g1[i] << ' ' << g2[i] << ' ' << g3[i] << '\n';

    std::cin >> name;

    for (int i = 0; i < 3; ++i)
        if (id[i] == name || na[i] == name)
        {
            del = true;
            cl[i] = 0;
        }

    if (!del)
    {
        std::cout << s.str();
        return 0;
    }

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    for (int i = 0; i < 3; ++i)
        if (cl[i])
            std::cout << id[i] << ' ' << cl[i] << ' ' << na[i] << ' ' << g1[i] << ' ' << g2[i] << ' ' << g3[i] << '\n';
    std::cout << "Are you sure(yes/no)?\n";

    char c;

    std::cin >> c;

    if (c == 'n')
        std::cout << s.str();

    return 0;
}