#include <iostream>
#include <vector>

typedef std::vector<int> IntVector;

int x = 1, y, dx = 1, dy = 0, N, i, t;

int main()
{
    std::cin >> N;
    std::vector<IntVector> v(N + 2, IntVector(N + 2, 0));

    for (y = N, i = 0; i < N + 2; ++i)
        v[i][0] = v[i][N + 1] = v[0][i] = v[N + 1][y] = 1;
    for (i = 0; i < N * N; x += dx, y += dy)
    {
        v[x][y] = ++i;
        if (v[x + dx][y + dy])
            t = dx, dx = dy, dy = -t;
    }

    for (x = 1; x <= N; ++x)
    {
        for (y = 1; y <= N; ++y)
            std::cout << (y == 1 ? "" : " ") << v[x][y];
        std::cout << std::endl;
    }

    return 0;
}
