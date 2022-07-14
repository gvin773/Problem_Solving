#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, adj[250][250], before, Next, p[250];

int Find(int x)
{
    if(p[x] < 0) return x;
    p[x] = Find(p[x]);
    return p[x];
}

void Merge(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px == py) return;
    if(p[px] < p[py])
    {
        p[px] += p[py];
        p[py] = x;
    }
    else
    {
        p[py] += p[px];
        p[px] = y;
    }
}

int main()
{
    onlycc;
    cin >> n >> m;

    memset(p, -1, sizeof(p));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
            if(adj[i][j]) Merge(i, j);
        }
    }

    cin >> before;
    for(int i = 1; i < m; i++)
    {
        cin >> Next;
        if(Find(before) != Find(Next))
        {
            cout << "NO";
            return 0;
        }
        before = Next;
    }
    cout << "YES";

    return 0;
}
