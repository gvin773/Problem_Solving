#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll tc, x1, Y1, x2, y2, n, x, y, r;

int d(int a,int b, int c, int d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ll ans = 0;
        cin >> x1 >> Y1 >> x2 >> y2 >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y >> r;
            if(d(x1,Y1,x,y) <= r*r && d(x2,y2,x,y) <= r*r) continue;
            if(d(x1,Y1,x,y) > r*r && d(x2,y2,x,y) > r*r) continue;
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
