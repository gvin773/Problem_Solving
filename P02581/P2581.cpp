#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int a[10001] = { 0 };

int main()
{
    int m, n, value = INF, sum = 0;

    scanf("%d%d", &m, &n);

    for(int i = 2; i <= n; i++)
    {
        if(a[i] == 0)
        {
            if(i >= m)
            {
                sum += i;
                value = min(value, i);
            }

            for(int j = 2; j*i <= n; j++)
                a[j*i] = -1;
        }
    }

    if(value == INF)
        printf("-1");

    else
        printf("%d\n%d", sum, value);

    return 0;
}
