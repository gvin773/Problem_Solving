#include <stdio.h>

int main()
{
    int a[10], count[42] = {0}, i, j, num = 0;

    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < 10; i++)
        a[i] = a[i] % 42;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 42; j++)
        {
            if(a[i] == j)
                count[j]++;
        }
    }

    for(i = 0; i < 42; i++)
    {
        if(count[i] != 0)
            num++;
    }

    printf("%d", num);

    return 0;
}
