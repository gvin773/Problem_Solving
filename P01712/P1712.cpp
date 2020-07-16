#include <iostream>
#include <cmath>

int main()
{
    int a, b, c;
    double x;

    scanf("%d%d%d", &a, &b, &c);

    if(c-b <= 0)
    {
        printf("-1");
        return 0;
    }

    x = a/(double)(c-b);

    if(x == (int)x)
        printf("%d", 1 + (int)x);

    else
        printf("%d", (int)ceil(x));

    return 0;
}
