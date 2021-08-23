#include <stdio.h>

int main()
{
    char str[101];
    int i;

    for(i = 0; i < 100; i++)
    {
        if(gets(str) == '\0')
            break;

        printf("%s\n", str);
    }
    return 0;
}
