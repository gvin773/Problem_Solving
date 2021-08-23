#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n, a, b, c, ans;
map<pii, int> m;
const int INF = 987654321;

ll gcd(ll x, ll y)
{
    if(x%y == 0) return y;
    return gcd(y, x%y);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if(a != 0 && b != 0)
        {
            int temp = gcd(max(abs(a),abs(b)), min(abs(a),abs(b)));
            a /= temp, b /= temp;
            if(a < 0 && b < 0) a = -a, b = -b;
            if(a < 0 && b > 0) a = -a, b = -b;
        }
        else if(a == 0) b = INF;
        else if(b == 0) a = INF;
        m.insert({make_pair(a, b), 0});
        m[{a, b}]++;
    }

    for(auto iter : m)
    {
        n -= iter.second;
        ans += iter.second*n;
    }

    cout << ans;

    return 0;
}
