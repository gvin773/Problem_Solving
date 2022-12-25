#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld a, b, c, d, m[4], M = -1;
ll ans;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d;
    m[0] = a/c+b/d, m[1] = c/d+a/b, m[2] = d/b+c/a, m[3] = b/a+d/c;
    for(int i = 0; i < 4; i++) if(M < m[i]) ans = i, M = m[i];
    cout << ans;

    return 0;
}
