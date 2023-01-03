#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, ans;
string x;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ans = 0;
        cin >> x;
        unordered_set<char> s;
        for(auto c : x) s.insert(c);
        for(int i = 'A'; i <= 'Z'; i++) if(s.find(i) == s.end()) ans += i;
        cout << ans << '\n';
    }

    return 0;
}
