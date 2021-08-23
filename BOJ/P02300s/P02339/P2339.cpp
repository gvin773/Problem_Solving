#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, arr[21][21];

int avail(int sizex, int sizey, int x, int y, int cnt, int i, int j)
{
    if(cnt == 1)
    {
        for(int k = y; k < y+sizey; k++)
        {
            if(arr[i][k] == 2)
                return 0;
        }
    }

    else
    {
        for(int k = x; k < x+sizex; k++)
        {
            if(arr[k][j] == 2)
                return 0;
        }
    }

    return 1;
}

int check(int sizex, int sizey, int x, int y, int dir)
{
    if(sizex>n || sizey>n || !(1<=x && x<=n) || !(1<=y && y<=n))
        return 0;

    int gem = 0, imnum = 0, a = 0, b = 0;

    for(int i = x; i < x+sizex; i++)
    {
        for(int j = y; j < y+sizey; j++)
        {
            if(arr[i][j] == 2)
                gem++;

            else if(arr[i][j] == 1)
                imnum++;
        }
    }

    if(gem == 0 || (gem == 1 && imnum >= 1) || (gem >= 2 && imnum == 0))
        return 0;

    if(gem == 1 && imnum == 0)
        return 1;

    for(int i = x; i < x+sizex; i++)
        for(int j = y; j < y+sizey; j++)
        {
            if(arr[i][j] == 1)
            {
                if(dir==0 && avail(sizex, sizey, x, y, 1, i, j)) a += check(i-x, sizey, x, y, 1) * check(sizex-i+x-1, sizey, i+1, y, 1);

                if(dir==1 && avail(sizex, sizey, x, y, 0, i, j)) b += check(sizex, j-y, x, y, 0) * check(sizex, y+sizey-j-1, x, j+1, 0);
            }
        }

    return a+b;
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);

    int ret = check(n, n, 1, 1, 0) + check(n, n, 1, 1, 1);
    printf("%d", (ret == 0) ? -1 : ret);

    return 0;
}
