#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 33333;
ll n, u, sn, v, A[SIZE], B[SIZE], dist[SIZE];
string num, snum;
vector<int> Edge[SIZE];
bool visited[SIZE];

void bfs()
{
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = 1e9;
    }

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto next : Edge[now])
        {
            if(B[next] != -1 && dist[B[next]] == 1e9)
            {
                dist[B[next]] = dist[now] + 1;
                q.push(B[next]);
            }
        }
    }
}

bool dfs(int now)
{
    for(auto next : Edge[now])
    {
        if(B[next] == -1 || (dist[B[next]] == dist[now]+1 && dfs(B[next])))
        {
            visited[now] = true;
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
    while(cin >> n)
    {
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) Edge[i].clear();
        for(int i = 0; i < n; i++)
        {
            cin >> num >> snum;
            u = stoi(num.substr(0, num.size()-1));
            sn = stoi(snum.substr(1, snum.size()-2));
            for(int j = 0; j < sn; j++)
            {
                cin >> v;
                Edge[u].push_back(v);
            }
        }

        int match = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        while(1)
        {
            bfs();

            int flow = 0;
            for(int i = 0; i < n; i++) if(!visited[i] && dfs(i)) flow++;
            if(!flow) break;

            match += flow;
        }
        cout << match << '\n';
    }

    return 0;
}
