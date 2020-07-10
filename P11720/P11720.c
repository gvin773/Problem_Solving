#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , i, num[1001], sum = 0;
    char a[1001];

    scanf("%d", &n);
    scanf("%s", a);

    for(i = 0; a[i] != '\0'; i++)
        num[i] = (int)a[i] - 48;

    for(i = 0; a[i] != '\0'; i++)
        sum += num[i];

    printf("%d", sum);

    return 0;
}
