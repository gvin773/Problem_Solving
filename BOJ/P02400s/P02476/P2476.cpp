#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, ans;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        vector<ll> v;
        for(int i = 0; i < 3; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        x = v[2];

        if(v.size() == 1) x = 10000 + v[0]*1000;
        else if(v.size() == 2) x = 1000 + x*100;
        else x = v[2]*100;

        ans = max(ans, x);
    }
    cout << ans;

    return 0;
}
