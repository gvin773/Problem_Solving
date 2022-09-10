#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int r, c, a[100][100], C, P, match, A[10100], B[10100], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<int> Edge[10100];
bool visited[10100];
string board[100];
vector<pii> cars, dist[10101];

bool dfs(int now)
{
    visited[now] = true;
    for(auto next : Edge[now])
    {
        if(B[next] == -1 || (!visited[B[next]] && dfs(B[next])))
        {
            A[now] = next;
            B[next] = now;
            return true;
        }
    }

    return false;
}

int main()
{
    onlycc;
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> board[i];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == 'P') a[i][j] = P++;
            if(board[i][j] == 'C')
            {
                a[i][j] = C++;
                cars.push_back({i, j});
            }
        }
    }
    if(P < C || C == 0)
    {
        cout << (C == 0 ? 0 : -1);
        return 0;
    }

    for(auto car : cars)
    {
        int x = car.first, y = car.second;

        queue<pii> q;
        bool V[100][100] = {};

        V[x][y] = true;
        q.push({x, y});

        int level = 0;
        while(!q.empty())
        {
            int Size = q.size();
            for(int z = 0; z < Size; z++)
            {
                auto now = q.front();
                q.pop();
                if(board[now.first][now.second] == 'P') dist[a[x][y]].push_back({level, a[now.first][now.second]});

                for(int i = 0; i < 4; i++)
                {
                    int nx = now.first+dx[i], ny = now.second+dy[i];
                    if(0 <= nx && nx < r && 0 <= ny && ny < c && !V[nx][ny] && board[nx][ny] != 'X')
                    {
                        V[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            level++;
        }
    }
    for(int i = 0; i < C; i++)
    {
        if(dist[i].empty())
        {
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < C; i++) sort(dist[i].begin(), dist[i].end());

    int lo = 0, hi = 1e9;
    while(lo+1 < hi)
    {
        for(int i = 0; i < C; i++) Edge[i].clear();
        int mid = (lo + hi) / 2;
        match = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));

        for(int i = 0; i < C; i++)
        {
            for(auto x : dist[i])
            {
                if(x.first > mid) break;
                Edge[i].push_back(x.second);
            }
        }

        for(int i = 0; i < C; i++)
        {
            if(A[i] == -1)
            {
                memset(visited, 0, sizeof(visited));
                if(dfs(i)) match++;
            }
        }

        if(match == C) hi = mid;
        else lo = mid;
    }
    cout << lo+1;

    return 0;
}
