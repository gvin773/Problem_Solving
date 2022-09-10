#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b;
string s;

int main()
{
    onlycc;
    while(1)
    {
        cin >> s >> a >> b;
        if(s == "#" && a == 0 && b == 0) break;
        cout << s;
        if(a > 17 || b >= 80) cout << " Senior\n";
        else cout << " Junior\n";
    }

    return 0;
}
