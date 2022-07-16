#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, u, v, b, k, d[300][300];

int main()
{
    onlycc;
    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 987654321;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> b;
        d[u-1][v-1] = 0;
        d[v-1][u-1] = !b;
    }
    for(int i = 0; i < n; i++) d[i][i] = 0;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> u >> v;
        cout << d[u-1][v-1] << '\n';
    }

    return 0;
}
