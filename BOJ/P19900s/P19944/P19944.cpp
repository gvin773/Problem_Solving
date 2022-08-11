#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m;

int main()
{
    onlycc;
    cin >> n >> m;
    if(m < 3) cout << "NEWBIE!";
    else if(2 < m && m <= n) cout << "OLDBIE!";
    else cout << "TLE!";

    return 0;
}
