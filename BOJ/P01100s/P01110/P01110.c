#include <stdio.h>

int main()
{
    int n, a, count = 0;

    scanf("%d", &n);
    a = n;

    for(; ; count++)
    {
        a = a%10*10 + (a/10+a%10)%10;
        if(a == n) break;
    }
    //if break, count++ does not work
    printf("%d", count+1);

    return 0;
}
