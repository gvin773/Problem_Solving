#include <stdio.h>

int main()
{
    int a[5], i, count = 0;

    for(i = 0; i < 5; i ++)
        scanf("%d", &a[i]);

    for(i = 0; i < 5; i ++)
    {
        if(a[i] < 40)
            a[i] = 40;
    }

    printf("%d", (a[0]+a[1]+a[2]+a[3]+a[4]) / 5);

    return 0;
}
