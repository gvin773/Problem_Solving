#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, o, a, b, p[1000001];

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
    for(int i = 0; i < m; i++)
    {
        cin >> o >> a >> b;
        if(o) cout << (Find(a) == Find(b) ? "YES\n" : "NO\n");
        else Merge(a, b);
    }

    return 0;
}
