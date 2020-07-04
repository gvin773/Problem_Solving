#include <stdio.h>
#include <math.h>

int main()
{
    int i, num1 = 0, num2 = 0;
    char str[2][4];

    scanf("%s%s", str[0], str[1]);

    for(i = 0; i < 3; i++)
    {
        num1 += ((int)str[0][i] - 48) * pow(10, i);
        num2 += ((int)str[1][i] - 48) * pow(10, i);
    }

    if(num1 > num2)
        printf("%d", num1);

    else
        printf("%d", num2);

    return 0;
}
