#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, paper[2188][2188], num[3]; //0->-1 1->0 2->1

void check(int s, int x, int y)
{
    int i, j, cnt = 0, temp = paper[x][y];
    for(i = x; i < x+s; i++)
    {
        for(j = y; j < y+s; j++)
        {
            if(temp != paper[i][j])
            {
                cnt = 1;
                break;
            }
        }

        if(cnt == 1) break;
    }

    if(i == x+s && j == y+s)
    {
        num[temp+1]++;
        return;
    }

    int ns = s/3;

    check(ns, x, y);
    check(ns, x, y+ns);
    check(ns, x, y+2*ns);

    check(ns, x+ns, y);
    check(ns, x+ns, y+ns);
    check(ns, x+ns, y+2*ns);

    check(ns, x+2*ns, y);
    check(ns, x+2*ns, y+ns);
    check(ns, x+2*ns, y+2*ns);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }

    check(n, 1, 1);

    printf("%d\n%d\n%d", num[0], num[1], num[2]);

    return 0;
}
