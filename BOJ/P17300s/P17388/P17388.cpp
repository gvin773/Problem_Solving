#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll s, k, h, m;

int main()
{
    onlycc;
    cin >> s >> k >> h;
    m = min(s, min(k, h));
    if(s+k+h <100)
    {
        if(s == m) cout << "Soongsil";
        if(k == m) cout << "Korea";
        if(h == m) cout << "Hanyang";
    }
    else cout << "OK";

    return 0;
}
