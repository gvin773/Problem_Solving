#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, count[101], len;
    char word[101];

    scanf("%s", word);
    len = strlen(word);

    for(i = 0; i <101; i++)
        count[i] = -1;

    for(i = len-1; i >= 0; i--)
        count[(int)word[i] - 97] = i;


    for(i = 0; i <26; i++)
        printf("%d ", count[i]);

    return 0;
}
