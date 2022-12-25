#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld n, v, a;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> a;
        v = (1 - (1-v*0.01)*(1-a*0.01))*100;
        cout.precision(10);
        cout << fixed << v << '\n';
    }

    return 0;
}
