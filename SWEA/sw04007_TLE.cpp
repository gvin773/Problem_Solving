#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int T, n, m, x, s, e, t, ans;

struct Edge
{
	int to;
	int cost;
	Edge(int to, int cost)
	{
		this->to = to;
		this->cost = cost;
	}
};

vector<int> dijkstra(vector<vector<Edge>>& v, int begin)
{
	vector<int> d;
	set<pii> pq;
	d.assign(v.size(), INF);
	d[begin] = 0;
	pq.insert(make_pair(0, begin));

	while(!pq.empty())
    {
		pii e = *pq.begin();
		pq.erase(e);

		for(int i = 0; i < v[e.second].size(); i++)
		{
			if(d[v[e.second][i].to] > d[e.second] + v[e.second][i].cost)
			{
				pq.erase(make_pair(d[v[e.second][i].to], v[e.second][i].to));
				d[v[e.second][i].to] = d[e.second] + v[e.second][i].cost;
				pq.insert(make_pair(d[v[e.second][i].to], v[e.second][i].to));
			}
		}
	}

	return d;
}

int main()
{
    onlycc;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> n >> m >> x;
        vector<vector<Edge>> v1, v2;
        v1.assign(n+1, vector<Edge>());
        v2.assign(n+1, vector<Edge>());
        for(int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            v1[s].push_back(Edge(e, t));
            v2[e].push_back(Edge(s, t));
        }

        ans = 0;
        vector<int> d1 = dijkstra(v1, x);
        vector<int> d2 = dijkstra(v2, x);
        for(int i = 1; i <= n; i++)
        {
            if(i != x && d1[i] != INF && d2[i] != INF) ans = max(ans, d1[i]+d2[i]);
        }

        cout << "#" << i << ' ' << ans << endl;
    }

    return 0;
}
