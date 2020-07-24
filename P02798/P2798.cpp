#include <iostream>
#include <algorithm>
using namespace std;

int card[101];
int n, m, ret;

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        scanf("%d", card+i);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(i != j && i != k && j != k)
                    if(card[i]+card[j]+card[k] <= m)
                        ret = max(ret, card[i]+card[j]+card[k]);

    printf("%d", ret);

    return 0;
}
