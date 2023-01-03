#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, y;
char c;

int main()
{
    onlycc;
    while(1)
    {
        cin >> x >> c >> y;
        if(x == 0 && c == 'W' && y == 0) break;
        if(c == 'D') cout << x+y << '\n';
        else if(x-y >= -200) cout << x-y << '\n';
        else cout << "Not allowed\n";
    }

    return 0;
}
