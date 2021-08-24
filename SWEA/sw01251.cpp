#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll t, n, parent[1001], x[1000], y[1000], ans;
long double e;

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
    parent[s2] = s1;
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> y[i];
        cin >> e;

        vector<pair<ll, pair<ll, ll>>> edge;
        for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++)
            edge.push_back({(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]), {i, j}});

        sort(edge.begin(), edge.end());
        for(int i = 0; i < n; i++) parent[i] = i;

        ans = 0;
        for(int i = 0; i < edge.size(); i++)
        {
            if(!sameroot(edge[i].second.first, edge[i].second.second))
            {
                union_set(edge[i].second.first, edge[i].second.second);
                ans += edge[i].first;
            }
        }

        cout << '#' << tc << ' ' << (ll)round(ans*e) << '\n';
    }

    return 0;
}
