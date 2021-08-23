#include <stdio.h>

int main()
{
    int t, i, r, j, k;
    char s[21];

    scanf("%d", &t);

    for(i = 0; i < t; i++)
    {
        scanf("%d", &r);
        scanf("%s", s);

        for(j = 0; s[j] != '\0'; j++)
        {
            for(k = 0; k < r; k++)
                printf("%c", s[j]);
        }

        puts("");
    }

    return 0;
}
