#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, x;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ll s = 0, m = 987654321;
        for(int i = 0; i < 7; i++)
        {
            cin >> x;
            s += (x&1 ? 0 : x);
            m = min(m, x&1 ? m : x);
        }
        cout << s << " " << m << '\n';
    }

    return 0;
}
