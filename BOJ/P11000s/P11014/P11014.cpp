#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, m, match, A[6666], B[6666], dx[6] = {-1, 0, 1, -1, 0, 1}, dy[6] = {-1, -1, -1, 1, 1, 1};
vector<int> Edge[6666];
bool visited[6666];
string room[100];

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
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> room[i];
        for(int i = 0; i < 6666; i++) Edge[i].clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(room[i][j] == 'x') continue;
                for(int z = 0; z < 6; z++)
                {
                    int nx = i+dx[z], ny = j+dy[z];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m && room[nx][ny] == '.') Edge[i*m+j].push_back(nx*m+ny);
                }
            }
        }

        match = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for(int i = 0; i < n*m; i++)
        {
            if((i%m)&1) continue;
            if(A[i] == -1)
            {
                memset(visited, 0, sizeof(visited));
                if(dfs(i)) match++;
            }
        }

        int xnum = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(room[i][j] == 'x') xnum++;
        cout << n*m-xnum-match << '\n';
    }

    return 0;
}
