#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll g, p, t;

int main()
{
    onlycc;
    cin >> g >> p >> t;
    if(g + p*t > g*p) cout << 1;
    else if(g + p*t < g*p) cout << 2;
    else cout << 0;

    return 0;
}
