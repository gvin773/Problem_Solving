#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, s, m = 101;

int main()
{
    onlycc;
    for(int i = 0; i < 7; i++)
    {
        cin >> x;
        if(x&1)
        {
            s += x;
            m = min(m, x);
        }
    }
    if(s) cout << s << '\n' << m;
    else cout << -1;

    return 0;
}
