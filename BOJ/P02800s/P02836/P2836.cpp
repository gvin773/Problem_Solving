#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, x, y, ans;
vector<pii> v, v2;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    for(int i = 0; i < n; i++) if(v[i].first > v[i].second) v2.push_back({v[i].second, v[i].first});
    sort(v2.begin(), v2.end());

    int L = v2[0].first, R = v2[0].second;
    for(int i = 1; i < v2.size(); i++)
    {
        if(v2[i].first <= R) R = max(R, v2[i].second);
        else
        {
            ans += (R-L);
            L = v2[i].first, R = v2[i].second;
        }
    }
    cout << m + 2*(ans+(R-L));

    return 0;
}
