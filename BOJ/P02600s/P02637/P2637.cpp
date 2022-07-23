#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, x, y, k, indegree[100], num[100][100], ans[100];
vector<ll> edge[100];
queue<ll> q;
unordered_set<ll> S;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> k;
        indegree[x-1]++;
        edge[y-1].push_back(x-1);
        num[x-1][y-1] = k;
    }

    for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i), num[i][i] = 1, S.insert(i);
    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            cout << 0;
            return 0;
        }

        ll now = q.front();
        q.pop();

        for(auto x : edge[now])
        {
            if(S.find(now) == S.end())
            {
                for(int j = 0; j < n; j++)
                {
                    if(S.find(j) != S.end())
                    {
                        num[x][j] += (num[now][j] * num[x][now]);
                    }
                }
            }
            if(--indegree[x] == 0) q.push(x);
        }
    }

    for(int i = 0; i < n; i++) if(S.find(i) != S.end()) cout << i+1 << ' ' << num[n-1][i] << '\n';

    return 0;
}
