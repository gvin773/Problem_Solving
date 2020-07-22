#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = 1; i <= n-1; i++)
    {
        for(j = 1; j <= (n-i); j++)
            printf(" ");

        printf("*");

        for(j = 1; j <= 2*(i-1)-1; j++)
            printf(" ");

        if(i != 1)
            printf("*");

        puts("");
    }

    for(j = 1; j <= 2*i-1; j++)
        printf("*");

    return 0;
}
