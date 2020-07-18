#include <iostream>
using namespace std;

int a[300000] = { 0 };

int main()
{
    int n, counter = 0;

    while(1)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 2; i <= 2*n; i++)
        {
            if(a[i] == 0 && i > n)
                counter++;

            for(int j = 2; j*i <= 2*n; j++)
                a[j*i] = -1;
        }

        printf("%d\n", counter);
        counter = 0;
    }

    return 0;
}
