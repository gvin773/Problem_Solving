#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tc;
string a, b;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b;
        if(a == b) cout << "OK\n";
        else cout << "ERROR\n";
    }

    return 0;
}
