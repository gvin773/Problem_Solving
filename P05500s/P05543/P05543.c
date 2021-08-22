#include <stdio.h>

int main()
{
    int a[3], b[2], min_a = 2000, min_b = 2000, i;

    for(i = 0; i < 3; i ++)
        scanf("%d", &a[i]);

    for(i = 0; i < 2; i ++)
        scanf("%d", &b[i]);

    for(i = 0; i < 3; i ++)
    {
        if(min_a > a[i])
            min_a = a[i];
    }

    for(i = 0; i < 2; i ++)
    {
        if(min_b > b[i])
            min_b = b[i];
    }

    printf("%d", min_a+min_b-50);

    return 0;
}
