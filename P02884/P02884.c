#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);

    c = a*60 + b - 45;

    if(c > 0)
        printf("%d %d", c/60, c%60);

    else if(c < 0)
        printf("%d %d", (24*60+c)/60, (24*60+c)%60);

    else
        printf("0 0");

    return 0;
}

