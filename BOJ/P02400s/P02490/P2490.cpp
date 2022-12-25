#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, s;

int main()
{
    onlycc;
    for(int i = 0; i < 3; i++)
    {
        s = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> x;
            s += x;
        }
        if(s == 4) cout << "E\n";
        if(s == 3) cout << "A\n";
        if(s == 2) cout << "B\n";
        if(s == 1) cout << "C\n";
        if(s == 0) cout << "D\n";
    }

    return 0;
}
