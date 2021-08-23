#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, p[1000], sum[1000];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", p+i);

    sort(p, p+n);

    sum[0] = p[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i-1] + p[i];

    int ret = 0;
    for(int i = 0; i < n; i++)
        ret += sum[i];

    printf("%d", ret);

    return 0;
}
