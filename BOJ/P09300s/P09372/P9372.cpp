#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, m, a, b;

int main()
{
    onlycc;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(m--) cin >> a >> b;
        cout << n-1 << '\n';
    }

    return 0;
}
