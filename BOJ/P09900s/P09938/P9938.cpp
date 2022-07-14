#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, l, a, b, p[300001], num[300001];

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
    cin >> n >> l;
    memset(p, -1, sizeof(p));
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(num[Find(a)] < -p[Find(a)])
        {
            int x = num[Find(a)];
            int y = num[Find(b)];
            Merge(a, b);
            num[Find(a)] = x+y+1;
            cout << "LADICA\n";
        }
        else if(num[Find(b)] < -p[Find(b)])
        {
            int x = num[Find(a)];
            int y = num[Find(b)];
            Merge(a, b);
            num[Find(a)] = x+y+1;
            cout << "LADICA\n";
        }
        else cout << "SMECE\n";
    }

    return 0;
}
