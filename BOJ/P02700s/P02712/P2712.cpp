#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc;
ld n;
string x;
map<string, string> m;
map<string, ld> mm;

int main()
{
    onlycc;
    m["kg"] = "lb";
    m["lb"] = "kg";
    m["l"] = "g";
    m["g"] = "l";
    mm["kg"] = 2.2046;
    mm["lb"] = 0.4536;
    mm["l"] = 0.2642;
    mm["g"] = 3.7854;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> x;
        cout.precision(4);
        cout << fixed << n*mm[x] << ' ' << m[x] << '\n';
    }

    return 0;
}
