#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, n, x[1001];

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int s = 1; s <= n; s++)
        {
            cin >> x[s];
            x[s] += x[s-1];
        }

        int ans = -987654321;
        for(int s = 1; s <= n; s++)
            for(int e = s; e <= n; e++)
                ans = max(ans, x[e] - x[s-1]);

        cout << ans << '\n';
    }

    return 0;
}
