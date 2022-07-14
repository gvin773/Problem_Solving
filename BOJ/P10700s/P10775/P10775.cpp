#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll g, P, x, p[100001], cnt;
bool flag;

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

    p[px] = py;
}

int main()
{
    onlycc;
    cin >> g >> P;
    memset(p, -1, sizeof(p));
    for(int i = 0; i < P; i++)
    {
        cin >> x;
        if(Find(x) != 0 && !flag)
        {
            Merge(Find(x), Find(x)-1);
            cnt++;
        }
        else flag = true;
    }
    cout << cnt;

    return 0;
}
