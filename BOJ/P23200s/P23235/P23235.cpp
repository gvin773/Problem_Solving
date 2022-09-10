#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x;

int main()
{
    onlycc;
    for(int tc = 1; ; tc++)
    {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++) cin >> x;
        cout << "Case " << tc << ": Sorting... done!\n";
    }

    return 0;
}
