#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, r, ans = 1;
vector<pii> v;
stack<pii> s;

bool cmp(pii &a, pii &b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> r;
        v.push_back({x-r, -1});
        v.push_back({x+r, 1});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto now : v)
    {
        if(now.second == -1) s.push(now);
        else
        {
            ll len = 0;
            while(!s.empty())
            {
                auto pre = s.top(); s.pop();
                if(pre.second == -1)
                {
                    if(len == now.first - pre.first) ans += 2;
                    else ans++;

                    s.push({now.first - pre.first, 2});
                    break;
                }
                else if(pre.second == 2) len += pre.first;
            }
        }
    }
    cout << ans;

    return 0;
}
