#include <stdio.h>

int d(int n, int a[]);

int main()
{
    int a[10040] = {0}, i;

    for(i = 1; i <= 10000; i++)
        d(i, a);

    for(i = 1; i <= 10000; i++)
    {
        if(a[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}

int d(int n, int a[])
{
    int dn = n;

    while(n / 10 != 0)
    {
        dn += n%10;
        n /= 10;
    }
    dn += n%10;

    a[dn] = 1;
}
