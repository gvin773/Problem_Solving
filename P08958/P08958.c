#include <stdio.h>

int main()
{
    int n, i, j, score, count;
    char str[80];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        score = 0;
        count = 0;

        scanf("%s", str);

        for(j = 0; str[j] != '\0'; j++)
        {
            if(str[j] == 'O')
            {
                count += 1;
                score += count;
            }

            else if(str[j] == 'X')
            {
                count = 0;
            }
        }

        printf("%d\n", score);
        str[0] = '\0';
    }

    return 0;
}
