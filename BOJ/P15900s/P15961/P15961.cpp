#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, d, k, c, a[3000000], eat[3001], cnt = 1, ans;

int main()
{
    onlycc;
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++) cin >> a[i];

    eat[c]++;
    for(int i = 0; i < k; i++)
    {
        if(!eat[a[i]]) cnt++;
        eat[a[i]]++;
    }
    ans = cnt;

    for(int i = 0; i < n; i++)
    {
        eat[a[i]]--;
        if(!eat[a[i]]) cnt--;

        int e = (i+k)%n;
        if(!eat[a[e]]) cnt++;
        eat[a[e]]++;

        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}
