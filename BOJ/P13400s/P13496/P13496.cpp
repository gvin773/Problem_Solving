#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k, n, s, d, dist, v;

int main()
{
    onlycc;
    cin >> k;
    for(int tc = 1; tc <= k; tc++)
    {
        int ans = 0;
        cin >> n >> s >> d;
        for(int i = 0; i < n; i++)
        {
            cin >> dist >> v;
            if(s*d >= dist) ans += v;
        }

        cout << "Data Set " << tc << ":\n" << ans << "\n\n";
    }

    return 0;
}
