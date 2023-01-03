#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, c, a[50], sum, ans;
vector<ll> v1, v2;

void dfs(int now, int start)
{
    if(now == n/2 && start == 0)
    {
        v1.push_back(sum);
        return;
    }
    if(now == n && start == n/2)
    {
        v2.push_back(sum);
        return;
    }

    dfs(now+1, start);
    sum += a[now];
    dfs(now+1, start);
    sum -= a[now];
}

int main()
{
    onlycc;
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1)
    {
        cout << 1+(int)(a[0] <= c);
        return 0;
    }

    dfs(0, 0);
    dfs(n/2, n/2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(auto x : v1)
    {
        if(x > c) break;
        ll lo = 0, hi = v2.size();
        while(lo+1 < hi)
        {
            ll mid = (lo+hi) / 2;
            if(x + v2[mid] <= c) lo = mid;
            else hi = mid;
        }

        ans += (lo+1);
    }
    cout << ans;

    return 0;
}
