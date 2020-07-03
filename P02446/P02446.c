#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = n; i >= 1; i--)
    {
        for(j = n; j > i; j--)
            printf(" ");

        for(j = 1; j <= 2*i - 1; j++)
            printf("*");

        puts("");
    }

    for(i = 1; i <= n-1; i++)
    {
        for(j = 1; j <= n-1-i; j++)
            printf(" ");

        for(j = 1; j <= 2*i + 1; j++)
            printf("*");

        puts("");
    }

    return 0;
}
