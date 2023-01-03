#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, ans = 1;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i*i <= n; i++) ans = i;
    cout << "The largest square has side length " << ans << ".";

    return 0;
}
