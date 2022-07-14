#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m, a, b, edges, vnum, ans;

void dfs(int now, bool visited[], vector<int> v[])
{
    if(visited[now]) return;

    visited[now] = true;
    vnum++;

    for(auto &next : v[now])
    {
        edges++;
        dfs(next, visited, v);
    }
}

int main()
{
    onlycc;
    for(int tc = 1; ; tc++)
    {
        cin >> n >> m;
        if(n == m && m == 0) break;

        vector<int> v[501];
        bool visited[501] = {};
        ans = 0;

        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                edges = 0;
                vnum = 0;
                dfs(i, visited, v);

                if(edges/2 == vnum-1) ans++;
            }
        }

        cout << "Case " << tc << ": ";
        if(ans == 0) cout << "No trees.\n";
        else if(ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }

    return 0;
}
