#include <stdio.h>

int main()
{
    int i, word = 0;
    char str[1000001], a;

    gets(str);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            word++;
    }

    word++;

    if(str[0] == ' ') //start
        word--;

    if(str[i-1] == ' ') //end
        word--;

    printf("%d", word);

    return 0;
}
