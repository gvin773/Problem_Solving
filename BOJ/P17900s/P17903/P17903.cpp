#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll m, n, a, b, c;

int main()
{
    onlycc;
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> a >> b >> c;
    if(m < 8) cout << "unsatisfactory";
    else cout << "satisfactory";

    return 0;
}
