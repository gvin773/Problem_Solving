#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k, m, Next[100001][31];

int main()
{
    onlycc;
    cin >> n >> k >> m;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i <= k; i++) cin >> Next[i][0];

    for(int j = 1; j < 31; j++)
    {
        for(int i = 1; i <= k; i++)
        {
            Next[i][j] = Next[Next[i][j-1]][j-1];
        }
    }

    m--;
    for(auto x : v)
    {
        for(ll j = 31; j >= 0; j--) if((m>>j)&1) x = Next[x][j];
        cout << x << ' ';
    }

    return 0;
}
