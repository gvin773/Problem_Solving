#include <iostream>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n-1; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < n; j++)
                printf("*");

            for(int j = 0; j < 2*n-3; j++)
                printf(" ");

            for(int j = 0; j < n; j++)
                printf("*");
        }

        else
        {
            for(int j = 0; j < i; j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < n-2; j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < 2*n-3-2*i; j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < n-2; j++)
                printf(" ");

            printf("*");
        }

        puts("");
    }

    for(int i = 0; i < n-1; i++)
        printf(" ");

    printf("*");

    for(int i = 0; i < n-2; i++)
        printf(" ");

    printf("*");

    for(int i = 0; i < n-2; i++)
        printf(" ");

    printf("*\n");

    for(int i = n-1; i > 0; i--)
    {
        if(i == 1)
        {
            for(int j = 0; j < n; j++)
                printf("*");

            for(int j = 0; j < 2*n-3; j++)
                printf(" ");

            for(int j = 0; j < n; j++)
                printf("*");
        }

        else
        {
            for(int j = 0; j < i-1; j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < n-2; j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < 2*n-3-2*(i-1); j++)
                printf(" ");

            printf("*");

            for(int j = 0; j < n-2; j++)
                printf(" ");

            printf("*");
        }

        puts("");
    }

    return 0;
}
