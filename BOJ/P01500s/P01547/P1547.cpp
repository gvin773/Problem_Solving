#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, y, ans = 1;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        if(x == ans) ans = y;
        else if(y == ans) ans = x;
    }
    cout << ans;

    return 0;
}
