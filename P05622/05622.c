#include <stdio.h>

int main()
{
    int i, time = 0, num;
    char str[16];

    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        num = (int)str[i];

        if(num <= 67) //until C
            time += 3;

        else if(num <= 70) //until F
            time += 4;

        else if(num <= 73) //until I
            time += 5;

        else if(num <= 76) //until L
            time += 6;

        else if(num <= 79) //until O
            time += 7;

        else if(num <= 83) //until S
            time += 8;

        else if(num <= 86) //until V
            time += 9;

        else if(num <=90) //until Z
            time += 10;
    }

    printf("%d", time);

    return 0;
}
