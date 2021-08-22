#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int N, M, a, b, game[101];

int bfs()
{
    queue<int> q;
    bool visited[101] = {};
    q.push(1);
    visited[1] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            if(now == 100) return level;
            q.pop();

            for(int n = 1; n <= 6; n++)
            {
                int next = now + n;
                if(game[next] != 0) next = game[next];
                if(next <= 100 && !visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        level++;
    }

    return 0;
}

int main()
{
    onlycc;
    cin >> N >> M;
    for(int i = 0; i < N+M; i++)
    {
        cin >> a >> b;
        game[a] = b;
    }

    cout << bfs();

    return 0;
}
