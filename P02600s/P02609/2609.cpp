#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, m = 1, n;
    scanf("%d%d", &a, &b);

    int temp = min(a, b);
    for(int i = 2; i <= temp; i++)
    {
        if(a%i == 0 && b%i == 0)
            m = i;
    }

    n = a*b;
    temp = max(a, b);
    for(int j = n; j >= temp; j--)
    {
        if(j%a == 0 && j%b == 0)
            n = j;
    }

    printf("%d\n%d", m, n);

    return 0;
}
