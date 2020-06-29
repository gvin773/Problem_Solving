#include <stdio.h>

int main()
{
    int i, c[26] = {0}, max, rep = -1;
    char w[1000001], a;

    scanf("%s", &w);

    for(i = 0; w[i] != '\0'; i++)
    {
        if((int)w[i] >=97) //small alphabet
            c[(int)w[i] - 97] += 1;

        else //large alphabet
            c[(int)w[i] - 65] += 1;
    }

    max = c[0];
    for(i = 1; i < 26; i++)
    {
        if(max < c[i])
            max = c[i];
    }

    for(i = 0; i < 26; i++)
    {
        if(max == c[i])
        {
            rep++;
            a = i;
        }
    }

    if(rep == 0) //not repeated
        printf("%c", a+65);

    else //repeated
        printf("?");

    return 0;
}
