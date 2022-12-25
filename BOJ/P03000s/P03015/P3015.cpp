#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[500000], same, ans;
stack<pll> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        same = 1;
        while(!s.empty() && s.top().first <= a[i])
        {
            if(s.top().first == a[i]) same = s.top().second+1;
            else same = 1;

            ans += s.top().second;
            s.pop();
        }

        if(!s.empty()) ans++;
        s.push({a[i], same});
    }
    cout << ans;

    return 0;
}
