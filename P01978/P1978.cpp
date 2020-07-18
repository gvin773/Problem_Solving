#include <iostream>

int num[1001];

int main()
{
    int n, counter = 0, j;
    scanf("%d", &n);

    for(int i = 1; i <= n; i ++)
        scanf("%d", &num[i]);

    for(int i = 1; i <= n; i++)
    {
        for(j = 2; j < num[i]; j++)
        {
            if(num[i] % j == 0)
                break;
        }

        if(j == num[i])
            counter++;
    }

    printf("%d", counter);

    return 0;
}
