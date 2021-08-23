#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int n, a, b, m;
vector<int> v[101];
bool visited[101], connected;
queue<int> q;

int bfs()
{
    q.push(a);
    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            int now = q.front();
            visited[now] = true;

            for(int i = 0; i < v[now].size(); i++)
            {
                if(v[now][i] == b)
                {
                    connected = true;
                    break;
                }

                if(!visited[v[now][i]])
                    q.push(v[now][i]);
            }

            q.pop();
        }

        level++;
        if(connected) break;
    }

    if(connected) return level;
    else return -1;
}

int main()
{
    onlycc;
    cin >> n >> a >> b >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << bfs();

    return 0;
}
