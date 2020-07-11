#include <stdio.h>

int num[1001] = { 0 };

int main()
{
    int i, j, k, n, sum;

    scanf("%d", &n);

    printf("%d", fib(n));

    return 0;
}

int fib(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(num[n] == 0)
        num[n] = fib(n-1) + fib(n-2);

    return num[n] % 10007;
}
