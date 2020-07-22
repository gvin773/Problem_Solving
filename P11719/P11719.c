#include <stdio.h>

int main()
{
    int i;
    char str[101];

    for(i = 0; i < 100; i++)
    {
        if(gets(str) == '\0')
            break;

        printf("%s\n", str);
    }

    return 0;
}
