#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, m, t1, t2, a, q, E, match, A[2020], B[2020];
vector<int> Edge[2020];
bool visited[2020];

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
        for(int i = 0; i < 2020; i++) Edge[i].clear();
        E = 0;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> t1 >> t2 >> a;
            E = max(E, t2);
            for(int j = 0; j < a; j++)
            {
                cin >> q;
                for(int z = t1; z < t2; z++) Edge[q].push_back(z);
            }
        }
        for(int i = 1; i <= n; i++) sort(Edge[i].begin(), Edge[i].end());

        match = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for(int i = 1; i <= n; i++)
        {
            if(A[i] == -1)
            {
                memset(visited, 0, sizeof(visited));
                if(dfs(i)) match++;
            }
        }
        if(match == n)
        {
            int t = E-1;
            while(B[t] == -1) t--;
            cout << t+1 << '\n';
        }
        else cout << -1 << '\n';
    }

    return 0;
}
