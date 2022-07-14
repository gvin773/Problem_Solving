#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll tc, f, p[200001], cnt;
string a, b;

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
    cin >> tc;
    while(tc--)
    {
        cin >> f;

        cnt = 0;
        unordered_map<string, int> m;
        memset(p, -1, sizeof(p));
        for(int i = 0; i < f; i++)
        {
            cin >> a >> b;
            if(m.find(a) == m.end()) m[a] = cnt++;
            if(m.find(b) == m.end()) m[b] = cnt++;
            Merge(m[a], m[b]);
            cout << -p[Find(m[a])] << '\n';
        }
    }

    return 0;
}
