#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        ll d = 0;
        while(n)
        {
            if(n&1) cout << d << ' ';
            n /= 2;
            d++;
        }
        cout << '\n';
    }

    return 0;
}
