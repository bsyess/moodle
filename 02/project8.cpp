#include <iomanip>
#include <iostream>

unsigned short idTmp, id[7] = { 10001  , 10002 , 10003  , 10004, 10005, 10006, 10007  };
unsigned short clTmp, cl[7] = { 11     , 12    , 11     , 11   , 14   , 12   , 13     };
std::string    naTmp, na[7] = { "Zhang", "Yang", "Liang", "Cai", "Fu" , "Mao", "Zhan" };
long double    g1Tmp, g1[7] = { 99.5   , 77.9  , 92.5   , 89.6 , 55.6 , 22.1 , 35.6   };
long double    g2Tmp, g2[7] = { 88.5   , 56.5  , 99.0   , 56.9 , 67.9 , 45.9 , 67.9   };
long double    g3Tmp, g3[7] = { 89.5   , 87.5  , 60.5   , 90.5 , 98.9 , 99.2 , 88.0   };

long double sum(size_t n) { return g1[n] + g2[n] + g3[n]; }

void sort()
{
    for (size_t i = 7; i; --i)
        for (size_t j = 1; j < i; ++j)
            if (cl[j - 1] == cl[j] && sum(j - 1) < sum(j) || cl[j - 1] > cl[j])
            {
                idTmp = id[j], id[j] = id[j - 1], id[j - 1] = idTmp;
                clTmp = cl[j], cl[j] = cl[j - 1], cl[j - 1] = clTmp;
                naTmp = na[j], na[j] = na[j - 1], na[j - 1] = naTmp;
                g1Tmp = g1[j], g1[j] = g1[j - 1], g1[j - 1] = g1Tmp;
                g2Tmp = g2[j], g2[j] = g2[j - 1], g2[j - 1] = g2Tmp;
                g3Tmp = g3[j], g3[j] = g3[j - 1], g3[j - 1] = g3Tmp;
            }
}

char from_classes()
{
    int beg, end;
    char sep;

    std::cin >> beg >> sep >> end;

    char result = 0;
    for (size_t i = 0; i < 7; ++i)
        if (cl[i] >= beg && cl[i] <= end)
            result |= 1 << i;

    return result;
}

char from_ids()
{
    int beg, end;
    char sep;

    std::cin >> beg >> sep >> end;

    char result = 0;
    for (size_t i = 0; i < 7; ++i)
        if (id[i] >= beg && id[i] <= end)
            result |= 1 << i;

    return result;
}

char from_name_with_wildcard()
{
    std::string pat;

    std::cin >> pat;
    pat.erase(pat.size() - 1);

    char result = 0;
    for (size_t i = 0; i < 7; ++i)
        if (na[i].substr(0, pat.size()) == pat)
            result |= 1 << i;

    return result;
}

char from_score()
{
    long double beg;

    std::cin >> beg;

    char result = 0;
    for (size_t i = 0; i < 7; ++i)
        if (sum(i) - beg >= -1e-6)
            result |= 1 << i;

    return result;
}

char from_ids_in_class()
{
    int clas, beg, end;
    char sep;
    
    std::cin >> clas >> sep >> beg >> sep >> end;

    char result = 0;
    for (size_t i = 0; i < 7; ++i)
        if (id[i] >= beg && id[i] <= end && cl[i] == clas)
            result |= 1 << i;

    return result;
}

char (*const search[6])() =
{
    0,
    from_classes,
    from_ids,
    from_name_with_wildcard,
    from_score,
    from_ids_in_class
};

int main()
{
    size_t mode;

    std::cin >> mode;

    sort();
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    char result = (*search[mode])();
    for (size_t i = 0; i < 7; ++i)
        if (1 << i & result)
            std::cout << id[i] << ' ' << cl[i] << ' ' << na[i] << ' ' << g1[i] << ' ' << g2[i] << ' ' << g3[i] << '\n';

    return 0;
}
