#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

class Edge
{
public:
    int v, cnt;
    Edge *inv;

    Edge() : Edge(-1, 0){}
    Edge(int v1, int cnt1) : v(v1), cnt(cnt1), inv(nullptr){}
};

ll n, x, deg[1000], s = -1, edge[1000][1000], checked[1000];
bool visited[1000];

int dfs(int now)
{
    int ret = 1;
    visited[now] = true;
    for(int i = 0; i < n; i++) if(!visited[i] && edge[now][i]) ret += dfs(i);

    return ret;
}

void Euler(int now)
{
    for(ll &i = checked[now]; i < n; i++)
    {
        if(edge[now][i])
        {
            edge[now][i]--;
            edge[i][now]--;
            deg[now]--;
            deg[i]--;

            Euler(i);
        }
    }

    cout << now+1 << ' ';
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x;
            if(x && i < j)
            {
                edge[i][j] = x;
                edge[j][i] = x;
                deg[i] += x;
                deg[j] += x;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(deg[i] & 1)
        {
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            int ret = dfs(i);
            if(ret > 1)
            {
                if(s == -1) s = i;
                else
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    if(s == -1) s = 0;
    Euler(s);

    return 0;
}
