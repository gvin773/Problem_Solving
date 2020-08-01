#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);

    if(n == 1) printf("*");

    else
    {
        for(i = 1; i < n; i++)
            printf(" ");

        printf("*\n");

        for(i = 2; i <= n; i++)
        {
            for(j = n; j > i; j--)
                printf(" ");

            printf("*");

            for(j = 1; j <= 2*(i-1)-1; j++)
                printf(" ");

            printf("*\n");
        }
    }
    return 0;
}
