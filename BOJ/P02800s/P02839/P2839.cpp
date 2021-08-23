#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
    int x = 0, y = 0, n, m = INF; //(3,x), (5, y)

    scanf("%d", &n);

    for(y = 0; 5*y <= n; y++)
    {
        for(x = 0; 3*x+5*y <= n; x++)
        {
            if(3*x+5*y == n)
                m = min(m, x+y);
        }
    }

    if(m == INF)
        printf("-1");

    else
        printf("%d", m);

    return 0;
}
