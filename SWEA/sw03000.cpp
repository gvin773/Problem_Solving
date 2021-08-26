#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#define MOD 20171109
using namespace std;

typedef long long ll;

ll t, n, a, x, y, ans;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        multiset<ll> s;
        ans = 0;

        cin >> n >> a;
        s.insert(a);
        auto iter =  s.begin();

        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            s.insert(x);
            s.insert(y);
            if(y < x) swap(x, y);
            if(x <= *iter && y <= *iter) iter--;
            else if(*iter <= x && *iter <= y) iter++;

            ans += *iter;
            ans %= MOD;
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
