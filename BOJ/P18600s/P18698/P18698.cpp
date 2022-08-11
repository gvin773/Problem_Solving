#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll t;
string s;

int main()
{
    onlycc;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << (s.find('D') == string::npos ? s.size() : s.find('D')) << '\n';
    }

    return 0;
}
