#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll s, x, ans, idx;

int main()
{
    onlycc;
    for(int i = 0; i < 5; i++)
    {
        s = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> x;
            s += x;
        }
        if(s > ans)
        {
            ans = s;
            idx = i+1;
        }
    }
    cout << idx << ' ' << ans;

    return 0;
}
