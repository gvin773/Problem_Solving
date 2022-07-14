#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, sum, lo, hi, ans;
bool Prime[4000001];
vector<ll> a;

int main()
{
    onlycc;
    fill(Prime, Prime+4000002, 1);
    cin >> n;
    for(ll i = 2; i <= n; i++)
    {
        if(!Prime[i]) continue;
        a.push_back(i);
        for(ll j = i*i; j <= n; j+=i) Prime[j] = false;
    }

    while(1)
    {
        if(sum >= n) sum -= a[lo++];
        else if(hi == a.size()) break;
        else sum += a[hi++];
        if(sum == n) ans++;
    }
    cout << ans;

    return 0;
}
