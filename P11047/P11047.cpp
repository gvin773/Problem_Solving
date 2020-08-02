#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, a[11];

    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    int num = 0;
    int temp = k;

    for(int i = n-1; temp != 0; i--)
    {
        if(a[i] <= temp)
        {
            num += (temp/a[i]);
            temp %= a[i];
        }
    }

    printf("%d", num);

    return 0;
}
