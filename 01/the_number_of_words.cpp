#include <iostream>

int main()
{
    std::string string;
    size_t count = 0;

    for (size_t count = 0; std::cin >> string; ++count)
        if (string == "done")
        {
            std::cout << "You entered a total of " << count << " words.";
            return 0;
        }

    return 1;
}