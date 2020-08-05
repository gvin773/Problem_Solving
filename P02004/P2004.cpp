#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ret[2];

void calc(int x, int n, char c)
{
    int counter = 0;

    if(x == 2)
    {
        for(long long i = 2; i <= n; i *= 2)
        {
            counter += n/i;
        }

        if(c == '+') ret[0] += counter;
        else ret[0] -= counter;
    }

    else
    {
        for(long long i = 5; i <= n; i *= 5)
        {
            counter += n/i;
        }

        if(c == '+') ret[1] += counter;
        else ret[1] -= counter;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    m = min(m, n-m);

    if(m == 0)
    {
        printf("0");
        return 0;
    }

    calc(2, n, '+');
    calc(5, n, '+');

    calc(2, (n-m), '-');
    calc(5, (n-m), '-');

    calc(2, m, '-');
    calc(5, m, '-');

    printf("%d", min(ret[0], ret[1]));

    return 0;
}
