#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, c, ans = 1;

int main()
{
    onlycc;
    while(1)
    {
        cin >> a;
        if(a == 0) break;
        for(int i = 0; i < a; i++)
        {
            cin >> b >> c;
            ans = ans*b - c;
        }
        cout << ans << '\n';
        ans = 1;
    }
    return 0;
}
