#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, y, ans;
vector<ll> a[10101], b[10101];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
    }

    for(int i = 0; i < 10101; i++)
    {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());

        for(int j = 0; j < a[i].size(); j+=2) ans += (a[i][j+1]-a[i][j]);
        for(int j = 0; j < b[i].size(); j+=2) ans += (b[i][j+1]-b[i][j]);
    }
    cout << ans;

    return 0;
}
