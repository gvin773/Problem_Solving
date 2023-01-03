#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int MOD = 1e9+7;

ll n, a[200000], ans = 1;
unordered_map<ll, ll> m;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for(auto iter : m)
    {
        if(iter.second == 1) ans = (ans*2)%MOD;
        else ans = ((ans%MOD)*((iter.second+1)%MOD))%MOD;
    }
    cout << (ans-1)%MOD;

    return 0;
}
