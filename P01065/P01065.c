#include <stdio.h>

int hansu(int i);

int main()
{
    int i, n, count = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        if(hansu(i))
            count += 1;
    }

    printf("%d", count);

    return 0;
}

int hansu(int i)
{
    int dif[3], a[4], j;

    for(j = 0; i / 10 != 0; j++)
    {
        a[j] = i % 10;
        i = i / 10;
    }
    a[j] = i;

    if(j == 0 || j == 1)
        return 1;

    else if(j == 3)
        return 0;

    else if(j == 2)
    {
        for(j = 0; j < 2; j++)
            dif[j] = a[j+1] - a[j];
    }

    if(dif[0] == dif[1])
        return 1;

    else
        return 0;
}
