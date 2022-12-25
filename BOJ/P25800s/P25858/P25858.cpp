#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, a[30], s;

int main()
{
    onlycc;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 0; i < n; i++) cout << x*a[i]/s << '\n';

    return 0;
}
