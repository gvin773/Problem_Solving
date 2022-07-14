#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll g, lo = 1, hi = 1;
set<ll> s;

int main()
{
    onlycc;
    cin >> g;

    while(1)
    {
        if(hi*hi-lo*lo == g) s.insert(hi);
        if(hi*hi-lo*lo > g && hi-lo == 1) break;
        else if(hi*hi-lo*lo >= g) lo++;
        else hi++;
    }
    for(auto x : s) cout << x << '\n';
    if(s.empty()) cout << -1;

    return 0;
}
