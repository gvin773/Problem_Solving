#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, a, b, c;
string str;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> str >> a >> b >> c;
        cout << str << ' ' << a+b+c << ' ';
        if(a+b+c < 55) cout << "FAIL\n";
        else if(a < 11 || b < 8 || c < 12) cout << "FAIL\n";
        else cout << "PASS\n";
    }

    return 0;
}
