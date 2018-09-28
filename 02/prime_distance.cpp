#include <iostream>

long const N = 1000004;
long prime[N], P = -1, n;
bool comp[N]{true, true};

int main()
{
    std::cin >> n;

    if (n < 3)
    {
        std::cout << "2 " << 2 - n;
        return 0;
    }

    long const M = n << 1 < N ? n << 1 : N;

    for (long i = 2; i < M; ++i)
    {
        if (!comp[i])
            prime[++P] = i;
        for (int j = 0; j <= P && i * prime[j] <= M; ++j)
        {
            comp[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }

    long m, l = 0, r = P;

    while (m = l + r >> 1, r - l > 1)
    {
        if (prime[m] < n)
            l = m;
        else if (prime[m] > n)
            r = m;
        else
        {
            std::cout << n << " 0";
            return 0;
        }
    }

    if ((r = prime[r]) - n < n - (l = prime[l]))
        std::cout << r << ' ' << r - n;
    else
        std::cout << l << ' ' << n - l;

    return 0;
}