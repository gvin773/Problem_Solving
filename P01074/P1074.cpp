#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int n, r, c, num;

void check(int s, int x, int y)
{
    int i, j;

    if((x+s-1) < r && (y+s-1) < c)
    {
        num += s*s;
        return;
    }

    if(s == 2)
    {
        for(i = x; i < x+2; i++)
        {
            for(j = y; j < y+2; j++)
            {
                num++;
                if(i == r && j == c)
                {
                    printf("%d", num-1);
                    exit(0);
                }
            }
        }

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
    scanf("%d%d%d", &n, &r, &c);

    check((int)pow(2,n), 0, 0);

    return 0;
}
