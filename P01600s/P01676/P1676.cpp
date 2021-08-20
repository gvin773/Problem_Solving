#include <iostream>
#include <algorithm>
using namespace std;

long long n, counter, save = 1, num[501], prime[100]; //prime number 96 == 503

int main()
{
    scanf("%lld", &n);

    for(int i = 2; i <= 500; i++)
    {
        for(int j = 2; i*j <= 500; j++)
            num[i*j] = 1;
    }

    int j = 1;
    for(int i = 2; i <= 510; i++)
    {
        if(!num[i])
        {
            prime[j] = i;
            j++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int temp = i;
        for(int j = 1; prime[j] <= temp; j++)
        {
            if(prime[j] != 2 && prime[j] != 5 && temp%prime[j] == 0)
            {
                temp /= prime[j];
                j--;
            }
        }

        if(save >= 1073741824) save = 1073741824;
        save *= temp;
        while(1)
        {
            if(save%10 == 0)
            {
                counter++;
                save /= 10;
            }

            else break;
        }
    }

    printf("%lld", counter);

    return 0;
}
