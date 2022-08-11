#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld x;

int main()
{
    onlycc;
    while(1)
    {
        cin >> x;
        if(x == 0) break;

        ld ans = 0;
        for(int i = 0; i < 5; i++) ans += pow(x, i);
        cout.precision(2);
        cout << fixed << ans << '\n';
    }
    return 0;
}
