#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tc, k;
bool Prime[1300000];
vector<ll> v;

int main()
{
    onlycc;
    cin >> tc;
    fill(Prime, Prime+1300000, 1);
    for(ll i = 2; i < 1300000; i++)
    {
        if(Prime[i]) v.push_back(i);
        else continue;

        for(ll j = i*i; j < 1300000; j+=i) Prime[j] = false;
    }
    while(tc--)
    {
        cin >> k;
        ll idx = lower_bound(v.begin(), v.end(), k) - v.begin();
        if(v[idx] == k) cout << 0 << '\n';
        else cout << v[idx] - v[idx-1] << '\n';
    }

    return 0;
}
