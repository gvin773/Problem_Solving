#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, c, d, cnt;

void f()
{
    ll ta = abs(a-b), tb = abs(b-c), tc = abs(c-d), td = abs(d-a);
    a = ta, b = tb, c = tc, d = td;
}
int main()
{
    onlycc;
    while(1)
    {
        cin >> a >> b >> c >> d;
        if(!a && !b && !c && !d) break;
        while(!(a == b && b == c && c == d && c == a))
        {
            cnt++;
            f();
        }
        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}
