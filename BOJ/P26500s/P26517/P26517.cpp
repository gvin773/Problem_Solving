#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll k, a, b, c, d;

int main()
{
    onlycc;
    cin >> k >> a >> b >> c >> d;
    if(a*k+b == c*k+d) cout << "Yes " << a*k+b;
    else cout << "No";

    return 0;
}
