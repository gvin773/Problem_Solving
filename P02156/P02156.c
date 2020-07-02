#include <stdio.h>

int max(int x, int y);

int main()
{
    int n, d[10001], a[10001][3], i, j, m;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    a[0][0] = 0, a[0][1] = 0, a[0][2] = 0;

    for(i = 1; i <= n; i++)
    {
        a[i][0] = max(a[i-1][0], a[i-1][1]);
        a[i][0] = max(a[i][0], a[i-1][2]);
        for(j = 1; j < 3; j++)
            a[i][j] = a[i-1][j-1]+d[i];

    }

    m = max(a[n][0], a[n][1]);
    m = max(m, a[n][2]);

    printf("%d", m);

    return 0;
}

int max(int x, int y)
{
    return x > y ? x : y;
}
