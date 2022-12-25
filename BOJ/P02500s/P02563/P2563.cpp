#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, y, ans;
bool arr[111][111];

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        for(int i = x; i < x+10; i++) for(int j = y; j < y+10; j++) arr[i][j] = true;
    }
    for(int i = 1; i <= 100; i++) for(int j = 1; j <= 100; j++) if(arr[i][j]) ans++;
    cout << ans;

    return 0;
}
