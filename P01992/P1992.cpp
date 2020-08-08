#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
char video[65][65];

void check(int s, int x, int y)
{
    int i, j, cnt = 0;
    char temp = video[x][y];
    for(i = x; i < x+s; i++)
    {
        for(j = y; j < y+s; j++)
        {
            if(temp != video[i][j])
            {
                cnt = 1;
                break;
            }
        }

        if(cnt == 1) break;
    }

    if(i == x+s && j == y+s)
    {
        printf("%c", temp);
        return;
    }

    int ns = s/2;

    printf("(");
    check(ns, x, y);
    check(ns, x, y+ns);

    check(ns, x+ns, y);
    check(ns, x+ns, y+ns);
    printf(")");
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf(" %c", &video[i][j]);

    check(n, 1, 1);

    return 0;
}
