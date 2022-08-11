#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, x, sum;
map<string, int> m;
string s;

int main()
{
    onlycc;
    cin >> a >> b;
    m["bedroom"] = 0;
    m["bathroom"] = 0;
    m["kitchen"] = 0;
    m["balcony"] = 0;
    m["other"] = 0;

    for(int i = 0; i < a; i++)
    {
        cin >> x >> s;
        m[s] += x;
        sum += x;
    }
    cout.precision(10);
    cout << sum << '\n' << m["bedroom"] << '\n' << (sum-0.5*m["balcony"])*b;

    return 0;
}
