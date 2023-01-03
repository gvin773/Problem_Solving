#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld x, y;

int main()
{
    onlycc;
    cin >> x >> y;
    x /= 100, y /= 100;
    cout.precision(10);
    cout << fixed << x*(1-y)/y/(1-x);

    return 0;
}
