#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, c, d, p, m, n;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> p >> m >> n;
    cout << ((p%(a+b)) <= a && p%(a+b)) + ((p%(c+d)) <= c && p%(c+d)) << '\n';
    cout << ((m%(a+b)) <= a && m%(a+b)) + ((m%(c+d)) <= c && m%(c+d)) << '\n';
    cout << ((n%(a+b)) <= a && n%(a+b)) + ((n%(c+d)) <= c && n%(a+b));

    return 0;
}
