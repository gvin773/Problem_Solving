#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, m, u, v, match, A[2000], B[2000];
vector<int> Edge[2000];
bool visited[2000];

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
        for(int i = 0; i < 2000; i++) Edge[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            Edge[u*2].push_back(v*2+1);
        }

        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));

        match = 0;
        for(int i = 0; i < 2*n; i++)
        {
            if(A[i] == -1)
            {
                memset(visited, 0, sizeof(visited));
                if(dfs(i)) match++;
            }
        }

        cout << match << '\n';
    }

    return 0;
}
