#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= (n+1)/2; j++)
            printf("* ");

        puts("");

        for(j = 1; j <= n/2; j++)
            printf(" *");

        puts("");
    }


    return 0;
}
