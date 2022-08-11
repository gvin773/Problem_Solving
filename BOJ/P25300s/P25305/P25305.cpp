#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, k, x[1000];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x+n);
    cout << x[n-k];

    return 0;
}
