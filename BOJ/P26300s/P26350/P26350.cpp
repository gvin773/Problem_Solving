#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, x, y;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        bool flag = false;
        y = 0;
        cout << "Denominations: ";
        while(n--)
        {
            cin >> x;
            cout << x << ' ';
            if(y*2 > x) flag = true;
            y = x;
        }
        if(flag) cout << "\nBad";
        else cout << "\nGood";
        cout << " coin denominations!\n\n";
    }

    return 0;
}
