#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, K[100], D[100], A[100], k, d, a, ans, x;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> m;
        for(int i = 0; i < m; i++) cin >> K[i] >> D[i] >> A[i];
        cin >> k >> d >> a;

        ans = 0;
        for(int i = 0; i < m; i++) ans += ((x = k*K[i] - d*D[i] + a*A[i]) < 0 ? 0 : x);
        cout << ans << '\n';
    }

    return 0;
}
