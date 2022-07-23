#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[1000000], idx[1000000], eidx, M = LLONG_MIN;
vector<ll> v, RLIS;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        if(v.empty())
        {
            v.push_back(a[i]);
            idx[i] = 0;
        }
        else if(v.back() < a[i])
        {
            v.push_back(a[i]);
            idx[i] = v.size()-1;
        }
        else
        {
            auto iter = lower_bound(v.begin(), v.end(), a[i]);
            *iter = a[i];
            idx[i] = iter-v.begin();
        }
    }
    cout << v.size() << '\n';

    for(int i = n-1; i >= 0; i--) if(idx[eidx] < idx[i]) eidx = i;
    RLIS.push_back(eidx);
    for(int i = eidx-1; i >= 0; i--)
    {
        if(a[i] < a[eidx] && idx[i]+1 == idx[eidx])
        {
            eidx = i;
            RLIS.push_back(i);
        }
    }
    for(auto iter = RLIS.rbegin(); iter != RLIS.rend(); iter++) cout << a[*iter] << ' ';

    return 0;
}
