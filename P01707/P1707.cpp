#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

int k, v, e, a, b, cnt, color[20001];
bool visited[20001];
queue<int> q;

bool bfs(int start, vector<int> ver[])
{
    visited[start] = true;
    q.push(start);

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            int now = q.front();
            q.pop();

            for(int i = 0; i < ver[now].size(); i++)
            {
                int next = ver[now][i];
                if(color[next] == 0)
                {
                    visited[next] = true;
                    q.push(next);
                    color[next] = (level%2==0 ? 1 : 2);
                }
                else if(color[next] == 1 && level%2 != 0) return false;
                else if(color[next] == 2 && level%2 == 0) return false;
            }
        }
        level++;
    }

    return true;
}

int main()
{
    onlycc;
    cin >> k;
    for(int t = 0; t < k; t++)
    {
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        while(!q.empty()) q.pop();
        cin >> v >> e;

        vector<int> ver[20001];
        for(int i = 0; i < e; i++)
        {
            cin >> a >> b;
            ver[a].push_back(b);
            ver[b].push_back(a);
        }

        for(cnt = 1; cnt <= v; cnt++)
            if(!visited[cnt] && !bfs(cnt, ver)) break;

        if(cnt == v+1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
