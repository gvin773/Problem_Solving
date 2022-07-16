#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll V, E, a, b, c, d[500][500], ans = LLONG_MAX;

int main()
{
    onlycc;
    cin >> V >> E;
    for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) d[i][j] = 10000000000LL;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        d[a-1][b-1] = c;
    }

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i = 0; i < V; i++) ans = min(ans, d[i][i]);
    cout << (ans == 10000000000LL ? -1 : ans);

    return 0;
}
