#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n, t = 0, no = 0;
    char str[100][101], count[26] = {0};

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%s", str[i]);

    for(i = 0; i < n; i++)
    {
        count[(int)str[i][0]-97] += 1;
        for(j = 1; str[i][j] != '\0'; j++)
        {
            count[(int)str[i][j]-97] +=1;

            if(count[(int)str[i][j]-97] >= 2)
            {
                if(str[i][j] != str[i][j-1])
                {
                    no++;
                    break;
                }
            }
        }

        for(k = 0; k < 26; k++)
            count[k] = 0;
    }

    printf("%d", n - no);

    return 0;
}
