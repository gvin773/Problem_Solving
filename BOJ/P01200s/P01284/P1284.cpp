#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n;
string s;

int main()
{
    onlycc;
    while(1)
    {
        cin >> s;
        if(s == "0") break;

        n = 0;
        for(auto x : s)
        {
            if(x == '1') n += 2;
            else if(x == '0') n += 4;
            else n += 3;
        }
        cout << n + s.size()-1 + 2 << '\n';
    }

    return 0;
}
