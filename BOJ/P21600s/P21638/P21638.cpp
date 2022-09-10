#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll t1, v1, t2, v2;

int main()
{
    onlycc;
    cin >> t1 >> v1 >> t2 >> v2;
    if(t2 < 0 && v2 >= 10) cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
    else if(t2 < t1) cout << "MCHS warns! Low temperature is expected tomorrow.";
    else if(v2 > v1) cout << "MCHS warns! Strong wind is expected tomorrow.";
    else cout << "No message";

    return 0;
}
