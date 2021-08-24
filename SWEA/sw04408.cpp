#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, n, s, e;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;

        int cnt[500] = {}, ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> s >> e;
            if(s & 1) s += 1;
            if(e & 1) e += 1;
            if(s <= e) for(int j = s; j <= e; j += 2) cnt[j]++;
            else for(int j = s; j >= e; j -= 2) cnt[j]++;
        }

        for(int i = 0; i < 410; i++) ans = max(ans, cnt[i]);
        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
