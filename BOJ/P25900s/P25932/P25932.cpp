#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, x, z;
string s;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        z = 0;
        for(int i = 0; i < 10; i++)
        {
            cin >> x;
            cout << x << ' ';
            if(x == 17) z += 1;
            if(x == 18) z += 2;
        }
        cout << '\n';

        if(z == 1) cout << "zack\n\n";
        else if(z == 2) cout << "mack\n\n";
        else if(z == 3) cout << "both\n\n";
        else cout << "none\n\n";
    }

    return 0;
}
