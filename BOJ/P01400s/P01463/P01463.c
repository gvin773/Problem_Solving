#include <stdio.h>

int d[1000001] = { 0 };
int min(int n);
int min_value(int x, int y);

int main()
{
    int i, n;

    scanf("%d", &n);
    printf("%d", min(n));

    return 0;
}

int min(int n)
{
    int res;

    if(n == 1) return 0;

    if(d[n] != 0) return d[n];

    res = min(n-1) + 1;
    if(n % 2 == 0) res = min_value(res, 1 + d[n/2]);
    if(n % 3 == 0) res = min_value(res, 1 + d[n/3]);

    d[n] = res;

    return res;
}

int min_value(int x, int y)
{
    return x < y ? x : y;
}
