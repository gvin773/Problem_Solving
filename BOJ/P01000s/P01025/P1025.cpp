#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, m, ans = -1;
string arr[9];

bool valid(ll a, ll b)
{
    return (0 <= a && a < n && 0 <= b && b < m);
}

bool square(ll x)
{
    return ((ll)sqrt(x))*((ll)sqrt(x)) == x;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int dx = -n+1; dx < n; dx++)
            {
                for(int dy = -m+1; dy < m; dy++)
                {
                    if(!valid(i+dx, j+dy)) continue;
                    ll ti = i, tj = j, num = 0, ten = 1;

                    while(valid(ti, tj))
                    {
                        num += ten*(arr[ti][tj] - '0');
                        if(square(num)) ans = max(ans, num);
                        ti += dx, tj += dy, ten *= 10;
                        if(dx == 0 && dy == 0) break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        if(square(arr[i][j] - '0')) ans = max(ans, (ll)arr[i][j] - '0');

    cout << ans;
    return 0;
}
