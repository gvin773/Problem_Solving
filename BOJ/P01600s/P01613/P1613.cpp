#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, k, d[500][500], a, b, s;

int main()
{
    onlycc;
    cin >> n >> k;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 987654321;
    for(int i = 0; i < k; i++)
    {
        cin >> a >> b;
        d[a-1][b-1] = 1;
    }

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

    cin >> s;
    for(int i = 0; i < s; i++)
    {
        cin >> a >> b;
        if(d[a-1][b-1] == 987654321 && d[b-1][a-1] == 987654321) cout << 0 << '\n';
        else if(d[a-1][b-1] != 987654321) cout << -1 << '\n';
        else cout << 1 << '\n';
    }

    return 0;
}
