#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll wc, hc, WS, hs;

int main()
{
    onlycc;
    cin >> wc >> hc >> WS >> hs;
    cout << (wc >= WS+2 && hc >= hs+2 ? 1 : 0);

    return 0;
}
