#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll h, w, n, m;

int main()
{
    onlycc;
    cin >> h >> w >> n >> m;
    cout << ((h-1)/(n+1)+1)*((w-1)/(m+1)+1);

    return 0;
}
