#include <stdio.h>

int main()
{
    int a[9], i, max, count;

    for(i = 0; i < 9; i++)
        scanf("%d", &a[i]);

    max = a[0];
    count = 1;
    for(i = 0; i < 9; i++)
    {
        if(max < a[i])
        {
            max = a[i];
            count = i+1;
        }
    }

    printf("%d\n%d", max, count);

    return 0;
}
