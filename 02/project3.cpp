#include <iomanip>
#include <iostream>

int main()
{
    char choice;

    std::cin >> choice;

    std::cout << "                              1.Input" << std::endl;
    std::cout << "                              2.Output" << std::endl;
    std::cout << "                              3.Order" << std::endl;
    std::cout << "                              4.Quit" << std::endl;
    if(choice == 'i')
    {
        int id1, id2, id3, id_temp;
        long double m1, m2, m3, p1, p2, p3, e1, e2, e3, t1, t2, t3, t_temp;

        std::cin >> id1 >> m1 >> p1 >> e1;
        std::cin >> id2 >> m2 >> p2 >> e2;
        std::cin >> id3 >> m3 >> p3 >> e3;

        t1 = m1 + p1 + e1;
        t2 = m2 + p2 + e2;
        t3 = m3 + p3 + e3;
        if(t2 < t1)
        {
            id_temp = id1, id1 = id2, id2 = id_temp;
            t_temp = t1, t1 = t2, t2 = t_temp;
        }
        if(t3 < t2)
        {
            id_temp = id2, id2 = id3, id3 = id_temp;
            t_temp = t2, t2 = t3, t3 = t_temp;
        }
        if(t2 < t1)
        {
            id_temp = id1, id1 = id2, id2 = id_temp;
            t_temp = t1, t1 = t2, t2 = t_temp;
        }

        std::cout << "Please input info of the three students:" << std::endl;
        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
        std::cout << id1 << ',' << t1 << ',' << t1 / 3 << std::endl;
        std::cout << id2 << ',' << t2 << ',' << t2 / 3 << std::endl;
        std::cout << id3 << ',' << t3 << ',' << t3 / 3 << std::endl; 
    }
    else if(choice == 'm')
        std::cout << "You are trying to Make things ordered";
    else if(choice == 'q')
        std::cout << "You are about to Quit";
    else
        std::cout << "Wrong input";

    return 0;
}