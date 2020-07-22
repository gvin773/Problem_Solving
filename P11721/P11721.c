#include <stdio.h>

int main()
{
    int i, j = 0, count = 0;
    char str[101];

    gets(str);

    while(1)
    {
        for(i = j; i < j + 10; i++)
        {
            if(str[i] == '\0')
            {
                count++;
                break;
            }

            printf("%c", str[i]);
        }

        puts("");

        if(count)
            break;

        j += 10;
    }

    return 0;
}
