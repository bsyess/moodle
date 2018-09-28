#include <iostream>

long long const spm = 60;
long long const mph = 60;
long long const hpd = 24;
long long const sph = spm * mph;
long long const spd = sph * hpd;

int main()
{
    long long seconds;

    std::cin >> seconds;

    std::cout << seconds << " seconds = " << seconds / spd << " days, " << seconds / sph % hpd << " hours, " << seconds / spm % mph << " minutes, " << seconds % spm << " seconds";

    return 0;
}