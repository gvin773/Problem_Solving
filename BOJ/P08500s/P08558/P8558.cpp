#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, ans = 1;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++) ans = (ans*i)%10;
    cout << ans;

    return 0;
}
