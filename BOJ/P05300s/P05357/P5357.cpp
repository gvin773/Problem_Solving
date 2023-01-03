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
    cin >> n;
    while(n--)
    {
        vector<char> v;
        cin >> s;
        for(auto x : s) v.push_back(x);
        v.erase(unique(v.begin(), v.end()), v.end());
        for(auto x : v) cout << x;
        cout << '\n';
    }

    return 0;
}
