#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, cnt;
string s;

int main()
{
    onlycc;
    cin >> n >> s;
    for(auto x : s) if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o') cnt++;
    cout << cnt;

    return 0;
}
