#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll P, w, c, v, p[10001], s, e, weight;
pair<int, pii> way[100000];

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
    if(p[px] <= p[py])
    {
        p[px] += p[py];
        p[py] = px;
    }
    else
    {
        p[py] += p[px];
        p[px] = py;
    }
}

int main()
{
    onlycc;
    cin >> P >> w;
    memset(p, -1, sizeof(p));
    for(int i = 0; i < w; i++)
    {
        cin >> s >> e >> weight;
        way[i] = {weight, {s,e}};
    }
    cin >> c >> v;

    sort(way, way+w);
    for(int i = w-1; i >= 0; i--)
    {
        Merge(way[i].second.first, way[i].second.second);
        if(Find(c) == Find(v))
        {
            cout << way[i].first;
            break;
        }
    }

    return 0;
}
