#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, s;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        s = 0;
        for(int i = 0; i < 3; i++)
        {
            cin >> x;
            s += (x >= 10);
            cout << x << ' ';
        }
        cout << '\n';

        if(s == 0) cout << "zilch\n";
        if(s == 1) cout << "double\n";
        if(s == 2) cout << "double-double\n";
        if(s == 3) cout << "triple-double\n";
        cout << '\n';
    }

    return 0;
}
