#include <stdio.h>

int main()
{
    int a[3], i, j, temp;

    scanf("%d%d%d", &a[0], &a[1], &a[2]);

    for(i = 2; i > 0; i --)
    {
        for(j = 0; j < i; j++)
        {
             if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("%d", a[1]);

    return 0;
}
