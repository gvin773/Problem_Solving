#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll m, M, ans;
bool Prime[1100000];

int main()
{
    onlycc;
    cin >> m >> M;
    fill(Prime, Prime+1100000, 1);
    for(ll i = 2; i <= 1000000; i++)
    {
        ll square = i*i;
        for(ll j = (m%square ? (m+1)/square : m/square) * square; j <= M; j += square) if(m <= j && j <= M) Prime[j-m] = false;
    }
    for(int i = 0; i <= M-m; i++) if(Prime[i]) ans++;
    cout << ans;

    return 0;
}
