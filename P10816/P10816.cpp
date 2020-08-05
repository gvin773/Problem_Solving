#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int num[20000001];

int main()
{
    int n, m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        num[a+10000000]++;
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int b;
        scanf("%d", &b);
        printf("%d ", num[b+10000000]);
    }

    return 0;
}
