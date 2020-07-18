#include <iostream>
using namespace std;

int apart[15][15];

int people(int k, int n)
{
    if(apart[k][n] != 0)
        return apart[k][n];

    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += people(k-1, i);

    return sum;
}

int main()
{
    int t, k, n;

    for(int i = 1; i <= 14; i++)
        apart[0][i] = i;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d%d", &k, &n);

         if(k == 0)
            printf("%d\n", n);

         else
            printf("%d\n", people(k, n));
    }

    return 0;
}
