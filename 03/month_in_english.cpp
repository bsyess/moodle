#include <iostream>

char const* month_in_english(size_t month)
{
    static char const*const MONTH_IN_ENGLISH[12] =
    {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"
    };
    return MONTH_IN_ENGLISH[month - 1];
}

int main()
{
    size_t month;
    std::cin >> month;
    std::cout << month_in_english(month);
    return 0;
}
