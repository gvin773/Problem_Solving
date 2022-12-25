#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, ans;

int main()
{
    onlycc;
    cin >> a >> b;
    for(int i = 0; i <= b; i++)
    {
        if(i*2 <= a) ans = i;
        else break;
    }
    cout << ans;

    return 0;
}
