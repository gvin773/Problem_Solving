#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, y, ans;
vector<pii> v;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int L = v[0].first, R = v[0].second;
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].first <= R) R = max(R, v[i].second);
        else
        {
            ans += (R-L);
            L = v[i].first, R = v[i].second;
        }
    }
    cout << ans + R-L;

    return 0;
}
