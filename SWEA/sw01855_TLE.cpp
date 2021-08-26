/*#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int t, n, ans, x, len;
vector<int> E_ptoc[100001], E_ctop[100001];

void get_LCA(int y, map<int, int> &m, vector<int> E[100001], int& LCA, int cnt)
{
    if(m.find(y) != m.end())
    {
        LCA = y;
        len = cnt;
        return;
    }

    for(int i : E[y])
        get_LCA(i, m, E, LCA, cnt+1);
}

void count_a(int now, map<int, int> &AP, vector<int> E[100001], int cnt)
{
    for(int i : E[now])
    {
        AP[i] = cnt++;
        count_a(i, AP, E, cnt);
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        for(int i = 1; i <= n; i++) E_ptoc[i].clear();
        for(int i = 1; i <= n; i++) E_ctop[i].clear();

        cin >> n;
        for(int i = 2; i <= n; i++)
        {
            cin >> x;
            E_ptoc[x].push_back(i);
            E_ctop[i].push_back(x);
        }

        ans = 0;


        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            for(int b : E_ptoc[a])
            {
                if(!visited[b])
                {
                    visited[b] = true;
                    q.push(b);
                }
            }

            if(!q.empty())
            {
                int b = q.front();
                map<int, int> a_parents, b_parents;

                count_a(a, a_parents, E_ctop, 0);
                int LCA = 987654321;
                a_parents[a] = 0;
                get_LCA(b, a_parents, E_ctop, LCA, 0);
                ans += len;

                count_a(b, b_parents, E_ctop, 0);
                LCA = 987654321;
                b_parents[b] = 0;
                get_LCA(a, b_parents, E_ctop, LCA, 0);
                ans += len;
            }
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
*/
