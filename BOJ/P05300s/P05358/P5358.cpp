#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

string s;

int main()
{
    onlycc;
    while(cin >> s)
    {
        for(auto &x : s)
        {
            if(x == 'i') x = 'e';
            else if(x == 'e') x = 'i';
            else if(x == 'I') x = 'E';
            else if(x == 'E') x = 'I';
        }
        cout << s << '\n';
    }

    return 0;
}
