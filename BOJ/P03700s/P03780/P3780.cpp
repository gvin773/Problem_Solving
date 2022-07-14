#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tc, n, p[20010], dist[20010], a, b;
char order;

int Find(int x)
{
    if(p[x] < 0) return x;
    int newp = Find(p[x]);
    dist[x] += dist[p[x]];
    p[x] = newp;
    return p[x];
}

void Merge(int x, int y)
{
    int py = Find(y);
    p[py] += p[x];
    p[x] = y;
    dist[x] = abs(y-x) % 1000;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        memset(p, -1, sizeof(p));
        memset(dist, 0, sizeof(dist));
        cin >> n;
        while(1)
        {
            cin >> order;
            if(order == 'O') break;
            if(order == 'E')
            {
                cin >> a;
                Find(a);
                cout << dist[a] << '\n';
            }
            if(order == 'I')
            {
                cin >> a >> b;
                Merge(a, b);
            }
        }
    }

    return 0;
}
