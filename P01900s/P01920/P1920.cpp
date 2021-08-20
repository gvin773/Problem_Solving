#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    set<int> num;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        num.insert(a);
    }

    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        set<int>::iterator iter = num.find(x);

        if(iter == num.end())
            printf("0\n");

        else printf("1\n");
    }
    return 0;
}
