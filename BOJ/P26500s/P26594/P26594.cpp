#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll ans = 1;
string s;

int main()
{
    onlycc;
    cin >> s;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] != s[0]) break;
        ans++;
    }
    cout << ans;

    return 0;
}
