#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int f, s, g, u, d, ans;
bool visited[1000001];
queue<int> q;

int bfs()
{
    q.push(s);
    visited[s] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();

        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            if(now == g) return level;

            if(now + u <= f && !visited[now+u])
            {
                q.push(now+u);
                visited[now+u] = true;
            }

            if(now - d >= 1 && !visited[now-d])
            {
                q.push(now-d);
                visited[now-d] = true;
            }

            q.pop();
        }

        level++;
    }

    return 46464646;
}

int main()
{
    onlycc;
    cin >> f >> s >> g >> u >> d;

    if((ans = bfs()) != 46464646) cout << ans;
    else cout << "use the stairs";

    return 0;
}
