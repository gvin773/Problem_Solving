#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll b, c, a1, a2;

int main()
{
    onlycc;
    cin >> b >> c >> a1 >> a2;
    cout.precision(10);
    cout << fixed << (b+sqrt(b*b+4*c)) / (ld)2;

    return 0;
}
