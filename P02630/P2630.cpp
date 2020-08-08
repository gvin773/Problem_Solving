#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, paper[129][129], num[2];

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
        num[temp]++;
        return;
    }

    int ns = s/2;

    check(ns, x, y);
    check(ns, x, y+ns);

    check(ns, x+ns, y);
    check(ns, x+ns, y+ns);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &paper[i][j]);

    check(n, 1, 1);

    printf("%d\n%d", num[0], num[1]);

    return 0;
}
