#include <iostream>
#include <algorithm>
using namespace std;

int r[100], n, denom[100],num[100];

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", r+i);

    for(int i = 1; i < n; i++)
        num[i] = r[0], denom[i] = r[i];

    for(int i = 1; i < n; i++)
    {
        if(r[0] > r[i]) //num > denom
        {
            for(int j = 2; j <= r[i]; j++)
            {
                if(num[i]%j == 0 && denom[i]%j == 0)
                {
                    num[i] /= j, denom[i] /= j;
                    j--;
                }
            }
        }

        else if(r[0] < r[i]) // num < denom
        {
            for(int j = 2; j <= r[0]; j++)
            {
                if(num[i]%j == 0 && denom[i]%j == 0)
                {
                    num[i] /= j, denom[i] /= j;
                    j--;
                }
            }
        }

        else //1/1
        {
            num[i] = 1, denom[i] = 1;
        }
    }

    for(int i = 1; i < n; i++)
        printf("%d/%d\n", num[i], denom[i]);

    return 0;
}
