#include <iostream>

int a[1000001];

int main()
{
    int m, n, j;

    scanf("%d%d", &m ,&n);

    a[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(j = 2; i*j <= n; j++)
                a[i*j] = 1;
    }

    for(int i = m; i <= n; i++)
        if(a[i] == 0)
           printf("%d\n", i);

    return 0;
}
