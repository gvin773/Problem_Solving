#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, c, ans;
string n;

void dfs(int now, int cnt)
{
    if(cnt == c || (c > n.size() && cnt == n.size()))
    {
        ans = max(ans, stoi(n));
        return;
    }

    for(int i = now; i < n.size(); i++)
    {
        for(int j = i+1; j < n.size(); j++)
        {
            swap(n[i], n[j]);
            dfs(i, cnt+1);
            swap(n[j], n[i]);
        }
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n >> c;
        ans = 0;
        dfs(0, 0);
        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
