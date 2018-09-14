#include <iomanip>
#include <iostream>

int main()
{
    int id1, id2, id3;
    long double m1, m2, m3, p1, p2, p3, e1, e2, e3;

    std::cin >> id1 >> m1 >> p1 >> e1;
    std::cin >> id2 >> m2 >> p2 >> e2;
    std::cin >> id3 >> m3 >> p3 >> e3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    std::cout << id1 << "  " << m1 << "  " << p1 << "  " << e1 << "  " << m1 + p1 + e1 << std::endl;
    std::cout << id2 << "  " << m2 << "  " << p2 << "  " << e2 << "  " << m2 + p2 + e2 << std::endl;
    std::cout << id3 << "  " << m3 << "  " << p3 << "  " << e3 << "  " << m3 + p3 + e3 << std::endl; 

    return 0;
}