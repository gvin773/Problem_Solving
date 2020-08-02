#include <iostream>
#include <algorithm>
using namespace std;

int cor[10000], d[10000];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", cor+i);

    sort(cor, cor+n);

    for(int i = 1; i < n; i++)
        d[i-1] = cor[i] - cor[i-1];

    sort(d, d+n-1);

    int i;
    for(i = 0; i < n-1; i++)
        if(d[i] > 0) break;

    n -= i;
    int ret = 0;
    for(int j = k; j < n; j++)
        ret += d[i++];

    printf("%d", ret);

    return 0;
}
