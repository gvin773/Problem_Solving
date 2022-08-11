#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld a;

int main()
{
    onlycc;
    cin >> a;
    cout.precision(10);
    cout << fixed << 2*M_PI*sqrt(a/M_PI);
    return 0;
}
