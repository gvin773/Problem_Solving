#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll p, q;

int main()
{
    onlycc;
    cin >> p >> q;
    if(p <= 50 && q <= 10) cout << "White";
    else if(q > 30) cout << "Red";
    else cout << "Yellow";

    return 0;
}
