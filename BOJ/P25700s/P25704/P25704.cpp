#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, p, ans;

int main()
{
    onlycc;
    cin >> n >> p;
    ans = p;
    if(n >= 5) ans = p-500;
    if(n >= 10) ans = min(ans, p/10*9);
    if(n >= 15) ans = min(ans, p-2000);
    if(n >= 20) ans = min(ans, p/4*3);
    cout << (ans > 0 ? ans : 0);

    return 0;
}
