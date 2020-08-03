#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    if(a%b == 0) return b;

    int r = a%b;
    int ret = gcd(b, r);

    return ret;
}

int main()
{
    int n, num[1000], d[1000], temp;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", num+i);

    for(int i = 0; i < n-1; i++)
        d[i] = abs(num[i+1] - num[i]);

    if(n != 2)
    {
        temp = gcd(max(d[0], d[1]), min(d[0], d[1]));

        for(int i = 2; i <= n-2; i++)
            temp = gcd(max(temp, d[i]), min(temp, d[i]));
    }

    else temp = d[0];

    for(int i = 2; i <= temp/2; i++)
        if(temp % i == 0) printf("%d ", i);

    printf("%d", temp);

    return 0;
}
