#include <iostream>

int a[10001];
int p[1250]; //1229

int main()
{
    int t, n, j, counter, p1, p2;

    scanf("%d", &t);

    a[1]= 1;
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        for(int i = 2; i <= n; i++)
            for(j = 2; i*j <= n; j++)
                a[i*j] = 1;

        counter = 0;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] == 0)
            {
                counter++;
                p[counter] = i;
            }
        }

        for(int i = counter; i > 0; i--)
        {
            for(int j = 1; j <= i; j++)
            {
                if(p[i] + p[j] == n)
                    p1 = p[i], p2 = p[j];
            }
        }

        printf("%d %d\n", p2, p1);
    }

    return 0;
}
