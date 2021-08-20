#include <stdio.h>

int max(int x, int y);

int main()
{
    int n, d[10001] = { 0 }, m[301], i, j;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    m[0] = 0, m[1] = d[1], m[2] = d[2] + d[1];
    for(i = 3; i <= n; i++)
        m[i] = max(m[i-2]+d[i], d[i] + d[i-1] + m[i-3]);


    printf("%d", m[n]);

    return 0;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

