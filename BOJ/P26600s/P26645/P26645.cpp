#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n;

int main()
{
    onlycc;
    cin >> n;
    if(n+5 <= 210) cout << 1;
    else if(n+3 <= 220) cout << 2;
    else if(n+2 <= 230) cout << 3;
    else cout << 4;

    return 0;
}
