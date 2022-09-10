#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld k;

int main()
{
    onlycc;
    cin >> k;
    k = 25 + 0.01*k;
    if(k < 100) cout << 100;
    else if(k > 2000) cout << 2000;
    else cout << k;

    return 0;
}
