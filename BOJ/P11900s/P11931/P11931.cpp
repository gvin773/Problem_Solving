#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, a[1000000];

bool cmp(ll x, ll y)
{
    return x > y;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++) cout << a[i] << '\n';

    return 0;
}
