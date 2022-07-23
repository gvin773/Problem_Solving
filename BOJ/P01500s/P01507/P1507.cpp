#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, d[30][30], ans;
bool visited[30][30];

int main()
{
    onlycc;
    cin >> n;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> d[i][j];

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || j == k || k == i) continue;
                if(d[i][j] == d[i][k] + d[k][j]) visited[i][j] = true;
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(!visited[i][j]) ans += d[i][j];
    cout << ans/2;

    return 0;
}
