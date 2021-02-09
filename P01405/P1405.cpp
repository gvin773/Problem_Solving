#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

/*
백트래킹을 이용하여 확률을 계산해준다. 확률의 오차를 줄이기 위해 그나마 정밀도가 높은 long double을 이용했다.
*/

ll n, p[4], a[4] = {0, 0, 1, -1}, b[4] = {1, -1, 0, 0};
bool visited[100][100];
long double ans;

void track(ll x, ll y, ll moved, long double pro)
{
    if(moved == n+1)
    {
        ans += pro;
        return;
    }

    visited[x][y] = true;
    for(ll i = 0; i < 4; i++)
    {
        ll nx = x+a[i], ny = y+b[i];
        if(!visited[nx][ny] && p[i] != 0)
        {
            track(nx, ny, moved+1, pro*p[i]/100);
            visited[nx][ny] = false;
        }
    }
}

int main()
{
    onlycc;
    cin >> n >> p[0] >> p[1] >> p[2] >> p[3];
    track(50, 50, 1, 1);

    cout << fixed;
    cout.precision(12);
    cout << ans;

    return 0;
}
