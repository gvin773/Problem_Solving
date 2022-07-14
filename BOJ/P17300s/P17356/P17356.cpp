#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    long double m = (b-a)/(double)400;

    cout.precision(10);
    cout << fixed;
    cout << 1 / (1+pow(10,m));

    return 0;
}
