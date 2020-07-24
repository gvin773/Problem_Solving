#include <iostream>
#include <cstring>
#include "stdio.h"
using namespace std;

char word[1001][1001];

int main()
{
    char str[1001];
    int num = 0, walk = 0, counter = 0, j = 0;

    gets(str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            num++;
            walk = 0;
        }

        else
        {
            word[num][walk] = str[i];
            walk++;
        }
    }

    for(int i = 0; word[i][0] != '\0'; i++)
    {
        if(counter == 0)
        {
            for(j = 0; word[i][j] != '\0'; j++)
            {
                if(word[i][j] == 'U')
                {
                    counter++;
                    break;
                }
            }
        }

        if(counter == 1)
        {
            for(; word[i][j] != '\0'; j++)
            {
                if(word[i][j] == 'C')
                {
                    counter++;
                    break;
                }
            }

            if(counter == 1)
                j = 0;
        }

        if(counter == 2)
        {
            for(; word[i][j] != '\0'; j++)
            {
                if(word[i][j] == 'P')
                {
                    counter++;
                    break;
                }
            }

            if(counter == 2)
                j = 0;
        }

        if(counter == 3)
        {
            for(; word[i][j] != '\0'; j++)
            {
                if(word[i][j] == 'C')
                {
                    counter++;
                    break;
                }
            }

            if(counter == 3)
                j = 0;
        }

        if(counter == 4)
            break;
    }

    if(counter == 4)
        printf("I love UCPC");

    else
        printf("I hate UCPC");

    return 0;
}
