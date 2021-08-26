/*#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll t, n, m, parent[50000], Rank[50000], s[50000], e[50000], c[50000], ans;

int find_root(int v)
{
    if(v == parent[v]) return v;
    return find_root(parent[v]);
}

bool sameroot(int s1, int s2)
{
    s1 = find_root(s1), s2 = find_root(s2);
    if(s1 == s2) return true;
    return false;
}

void union_set(int s1, int s2)
{
    if(s1 == s2) return;
    s1 = find_root(s1), s2 = find_root(s2);
    if(Rank[s1] > Rank[s2]) swap(s1, s2);
    parent[s2] = s1;
    if(Rank[s1] == Rank[s2]) Rank[s1]++;
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        for(int i = 0; i < m; i++) cin >> s[i] >> e[i] >> c[i];

        vector<pair<ll, pair<ll, ll>>> edge;
        for(int i = 0; i < m; i++) for(int j = i+1; j < m; j++)
            edge.push_back({c[i], {s[i], e[i]}});

        sort(edge.begin(), edge.end());
        for(int i = 0; i < n; i++) parent[i] = i;
        for(int i = 0; i < n; i++) Rank[i] = 1;

        ans = 0;
        for(int i = 0; i < edge.size(); i++)
        {
            if(!sameroot(edge[i].second.first, edge[i].second.second))
            {
                union_set(edge[i].second.first, edge[i].second.second);
                ans += edge[i].first;
            }
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
*/
