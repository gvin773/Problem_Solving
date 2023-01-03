#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, ans;
string x;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(stoi(x.substr(2)) <= 90) ans++;
    }
    cout << ans;

    return 0;
}
