#include <iostream>
using namespace std;

int main()
{
    unsigned int t, x, y, n, minv, sum;

    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d%d", &x, &y);
        minv = y - x;

        for(n = 1; n*n <= y-x; n++)
            ;

        n -= 1;

        if(n*n == y-x)
            printf("%d\n", 2*n-1);

        else if(y-x == 3)
            printf("3\n");

        else
        {
            sum = n*n;
            minv = 2*n-1;
            for(int i = 0; i < n; i++)
            {
                while(1)
                {
                    if(sum+n-i <= y-x)
                    {
                        minv++;
                        sum += n-i;
                    }

                    break;
                }
            }

            printf("%d\n", minv);
        }
    }

    return 0;
}
