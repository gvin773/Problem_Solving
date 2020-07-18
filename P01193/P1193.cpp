#include <iostream>

int main()
{
    int x, n, i = 1, j = 1;

    scanf("%d", &x);

    for(n = 1; n*(n+1)/2 < x; n++)
        ;

    if(n%2 == 0)
    {
        i = 1, j = n;
        for(n = 1 + n*(n-1)/2; n != x; n++)
            i++, j--;
    }

    else if(n%2 == 1 && n != 1)
    {
        i = n, j = 1;
        for(n = 1 + n*(n-1)/2; n != x; n++)
            i--, j++;
    }

    printf("%d/%d", i, j);

    return 0;
}
