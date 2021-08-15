#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int h1, w1, h2, w2, dp[51][51], Ldp[51][51][51][51];

int get_sq(int x, int y)
{
    if(x < y) swap(x, y);
    if(dp[x][y] != -1) return dp[x][y];
    if(x%y == 0) return dp[x][y] = x/y;

    int &ret = dp[x][y] = 987654321;
    if(x > 3*y) ret = get_sq(x-y, y)+1;
    else
    {
        for(int i = 1; i <= x/2; i++) ret = min(ret, get_sq(i, y) + get_sq(x-i, y));
        for(int i = 1; i <= y/2; i++) ret = min(ret, get_sq(x, i) + get_sq(x, y-i));
    }
    return ret;
}

int get_L(int x1, int y1, int x2, int y2)
{
    if(Ldp[x1][y1][x2][y2] != -1) return Ldp[x1][y1][x2][y2];

    int &ret = Ldp[x1][y1][x2][y2] = 987654321;
    for(int i = 1; i < x1; i++)
    {
        if(i > x2) ret = min(ret, get_L(i, y1, x2, y2) + get_sq(x1-i, y1));
        else if(i < x2) ret = min(ret, get_sq(i, y1-y2) + get_L(x1-i, y1, x2-i, y2));
        else ret = min(ret, get_sq(i, y1-y2) + get_sq(x1-i, y1));
    }

    for(int i = 1; i < y1; i++)
    {
        if(i < y1-y2) ret = min(ret, get_sq(x1, i) + get_L(x1, y1-i, x2, y2));
        else if(i == y1-y2) ret = min(ret, get_sq(x1, i) + get_sq(x1-x2, y2));
        else ret = min(ret, get_L(x1, i, x2, y2-y1+i) + get_sq(x1-x2, y1-i));
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> h1 >> w1 >> h2 >> w2;
    memset(dp, -1, sizeof(dp));
    memset(Ldp, -1, sizeof(Ldp));
    for(int i = 1; i <= 50; i++) dp[i][i] = 1;
    cout << get_L(h1, w1, h2, w2);

    return 0;
}
