#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll p[4], x, y, r, a;

int main()
{
    onlycc;
    for(int i = 0; i < 4; i++) cin >> p[i];
    cin >> x >> y >> r;
    for(int i = 0; i < 4; i++)
    {
        if(x == p[i])
        {
            a = i+1;
            break;
        }
    }
    cout << a;

    return 0;
}
