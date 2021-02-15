#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

int n, ans;
string fr[50];
bool visited[50];
queue<int> q;

int bfs(int start)
{
    visited[start] = true;
    q.push(start);

    int level = 0, ret = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            if(level == 2) return ret;

            int now = q.front();
            q.pop();

            for(int i = 0; i < n; i++)
            {
                if(fr[now][i] == 'Y' && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                    ret++;
                }
            }
        }
        level++;
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> fr[i];
    for(int i = 0; i < n; i++)
    {
        memset(visited, 0, sizeof(visited));
        while(!q.empty()) q.pop();
        ans = max(ans, bfs(i));
    }
    cout << ans;

    return 0;
}
