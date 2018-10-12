#include <iomanip>
#include <iostream>

int id[4] = {10001, 10002, 10003};
int cl[4] = {11, 12, 11};
std::string na[4] = {"Zhang", "Yang", "Liang"};
long double g1[4] = {99.5, 77.9, 92.5};
long double g2[4] = {88.5, 56.5, 99.0};
long double g3[4] = {89.5, 87.5, 60.5};

int main()
{
    std::cin >> id[3] >> cl[3] >> na[3] >> g1[3] >> g2[3] >> g3[3];

    if (id[3] >= 10001 && id[3] <= 10003)
    {
        cl[id[3] - 10001] = cl[3];
        na[id[3] - 10001] = na[3];
        g1[id[3] - 10001] = g1[3];
        g2[id[3] - 10001] = g2[3];
        g3[id[3] - 10001] = g3[3];
    }
    for (int i = 2; i; --i)
        for (int j = i; j; --j)
            if (cl[j] == cl[j - 1] && g1[j] + g2[j] + g3[j] > g1[j - 1] + g2[j - 1] + g3[j - 1] || cl[j] < cl[j - 1])
            {
                std::string sT;
                int iT;
                long double fT;

                iT = id[j], id[j] = id[j - 1], id[j - 1] = iT;
                iT = cl[j], cl[j] = cl[j - 1], cl[j - 1] = iT;
                sT = na[j], na[j] = na[j - 1], na[j - 1] = sT;
                fT = g1[j], g1[j] = g1[j - 1], g1[j - 1] = fT;
                fT = g2[j], g2[j] = g2[j - 1], g2[j - 1] = fT;
                fT = g3[j], g3[j] = g3[j - 1], g3[j - 1] = fT;
            }

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    std::cout << cl[0] << ' ' << id[0] << ' ' << na[0] << ' ' << g1[0] << ' ' << g2[0] << ' ' << g3[0];
    if (id[0] == id[3])
        std::cout << " modified";
    std::cout << std::endl;
    if (cl[0] == cl[1])
        std::cout << "   ";
    else
        std::cout << cl[1] << ' ';
    std::cout << id[1] << ' ' << na[1] << ' ' << g1[1] << ' ' << g2[1] << ' ' << g3[1];
    if (id[1] == id[3])
        std::cout << " modified";
    std::cout << std::endl;
    if (cl[1] == cl[2])
        std::cout << "   ";
    else
        std::cout << cl[2] << ' ';
    std::cout << id[2] << ' ' << na[2] << ' ' << g1[2] << ' ' << g2[2] << ' ' << g3[2];
    if (id[2] == id[3])
        std::cout << " modified";

    return 0;
}