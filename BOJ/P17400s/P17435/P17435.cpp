#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll m, Next[200001][20], q, n, x;

int main()
{
    onlycc;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> Next[i][0];

    for(int j = 1; j < 20; j++)
    {
        for(int i = 1; i <= m; i++)
        {
            Next[i][j] = Next[Next[i][j-1]][j-1];
        }
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> n >> x;

        for(int j = 19; j >= 0; j--) if((n>>j)&1) x = Next[x][j];
        cout << x << '\n';
    }


    return 0;
}
