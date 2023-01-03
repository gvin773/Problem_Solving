#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, s, a[50], sum, ans;
unordered_map<ll, ll> m1, m2;

void dfs(int now, int start)
{
    if(now == n/2 && start == 0)
    {
        if(m1.find(sum) == m1.end()) m1[sum] = 1;
        else m1[sum]++;
        return;
    }
    if(now == n && start == n/2)
    {
        if(m2.find(sum) == m2.end()) m2[sum] = 1;
        else m2[sum]++;
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
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1)
    {
        cout << (int)(s == a[0]);
        return 0;
    }

    dfs(0, 0);
    dfs(n/2, n/2);
    for(auto x : m1)
    {
        auto y = m2.find(s - x.first);
        if(y != m2.end()) ans += x.second*y->second;
    }

    cout << (s == 0 ? ans-1 : ans);

    return 0;
}
