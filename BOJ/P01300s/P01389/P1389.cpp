#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, a, b, ans = 987654321, idx;
vector<int> v[101];

int bfs(int s, int e)
{
    bool visited[101] = {};
    queue<int> q;
    q.push(s);
    visited[s] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int cur = q.front();
            q.pop();
            if(cur == e) return level;

            for(int next: v[cur])
            {
                if(!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        level++;
    }

    return level;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 1; j <= n; j++)
        {
            sum += bfs(i, j);
        }
        if(sum < ans) ans = sum, idx = i;
        if(sum == ans) idx = min(idx, i);
    }
    cout << idx;

    return 0;
}
