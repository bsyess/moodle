#include <iomanip>
#include <iostream>

int main()
{
    int id1, id2, id3, class1, class2, class3, int_temp;
    long double m1, m2, m3, p1, p2, p3, e1, e2, e3, t1, t2, t3, t_temp;

    std::cin >> id1 >> class1 >> m1 >> p1 >> e1;
    std::cin >> id2 >> class2 >> m2 >> p2 >> e2;
    std::cin >> id3 >> class3 >> m3 >> p3 >> e3;

    t1 = m1 + p1 + e1;
    t2 = m2 + p2 + e2;
    t3 = m3 + p3 + e3;
    if(class1 == class2 && t2 < t1 || class1 < class2)
    {
        int_temp = class1, class1 = class2, class2 = int_temp;
        int_temp = id1, id1 = id2, id2 = int_temp;
        t_temp = t1, t1 = t2, t2 = t_temp;
    }
    if(class2 == class3 && t3 < t2 || class2 < class3)
    {
        int_temp = class2, class2 = class3, class3 = int_temp;
        int_temp = id2, id2 = id3, id3 = int_temp;
        t_temp = t2, t2 = t3, t3 = t_temp;
    }
    if(class1 == class2 && t2 < t1 || class1 < class2)
    {
        int_temp = class1, class1 = class2, class2 = int_temp;
        int_temp = id1, id1 = id2, id2 = int_temp;
        t_temp = t1, t1 = t2, t2 = t_temp;
    }

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    std::cout << class1 << ',' << id1 << ',' << t1;
    if(class1 == class2)
        std::cout << ';';
    else
        std::cout << std::endl << class2 << ',';
    std::cout << id2 << ',' << t2;
    if(class2 == class3)
        std::cout << ';';
    else
        std::cout << std::endl << class3 << ',';
    std::cout << id3 << ',' << t3;

    return 0;
}