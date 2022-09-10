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
    int E, Capacity, F, Cost;
    Edge* dual;

    Edge() : Edge(-1, 0, 0){}
    Edge(int E1, int C1) : E(E1), Capacity(C1), F(0), Cost(0), dual(nullptr){}
    Edge(int E1, int C1, int C2) : E(E1), Capacity(C1), F(0), Cost(C2), dual(nullptr){}

    int get_R() { return Capacity-F; }
    void update_F(int F1)
    {
        F += F1;
        dual->F -= F1;
    }
};

const int SIZE = 5000;
ll n, k, h, m, x[SIZE], y[SIZE], hx[SIZE], hy[SIZE], mx[SIZE], my[SIZE], start, fin, level[SIZE], used[SIZE];
vector<Edge*> adj[SIZE];

bool bfs()
{
    memset(level, -1, sizeof(level));
    level[start] = 0;

    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto &e : adj[now])
        {
            int next = e->E;
            if(level[next] == -1 && e->get_R() > 0)
            {
                level[next] = level[now] + 1;
                q.push(next);
            }
        }
    }

    return level[fin] != -1;
}

int dfs(int now, int target, int flow)
{
    if(now == target) return flow;

    for(auto &i = used[now]; i < adj[now].size(); i++)
    {
        auto e = adj[now][i];
        int next = e->E;

        if(level[next] == level[now]+1 && e->get_R() > 0)
        {
            int residual = dfs(next, target, min(flow, e->get_R()));
            if(residual > 0)
            {
                e->update_F(residual);
                return residual;
            }
        }
    }

    return 0;
}

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    ll ret = x1*y2 - x2*y1;
    return (ret == 0 ? 0 : (ret > 0 ? 1 : -1));
}

bool check_same(ll a, ll b, ll c, ll d)
{
    if(a == c && b == d) return true;
    return false;
}

bool check(ll x1, ll y1, ll x2, ll y2, ll hi, ll mi)
{
    ll X1 = hx[hi], Y1 = hy[hi], X2 = mx[mi], Y2 = my[mi];

    if(x2 < x1 || (x1 == x2 && y2 < y1))
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    if(X2 < X1 || (X1 == X2 && Y2 < Y1))
    {
        swap(X1, X2);
        swap(Y1, Y2);
    }
    vector<pair<pii, pii>> line;
    line.push_back({{x1, y1}, {x2, y2}});
    line.push_back({{X1, Y1}, {X2, Y2}});

    bool flag = true;
    for(int i = 0; i < 2; i++)
    {
        auto before = line[i];
        auto now = line[(i+1)%2];

        ll x1 = before.first.first, y1 = before.first.second, x2 = before.second.first, y2 = before.second.second;
        ll a = now.first.first, b = now.first.second, c = now.second.first, d = now.second.second;

        if(a < x1 || (a == x1 && b < y1))
        {
            swap(x1, a);
            swap(y1, b);
            swap(x2, c);
            swap(y2, d);
        }

        if(x1 == x2 && x2 == a && a == c)
        {
            if(y2 >= b) flag = false;
            else continue;
        }
        else if(y1 == y2 && y2 == b && b == d)
        {
            if(x2 >= a) flag = false;
            else continue;
        }
        else if((y2-y1)*(a-x2) == (b-y2)*(x2-x1) && (b-y2)*(c-a) == (d-b)*(a-x2))
        {
            if(x2 >= a) flag = false;
            else continue;
        }
        else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, d-b, x1-c, y1-d) * cross(c-a, d-b, x2-c, y2-d) <= 0) flag = false;
    }

    return flag;
}

int main()
{
    onlycc;
    cin >> n >> k >> h >> m;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < h; i++) cin >> hx[i] >> hy[i];
    for(int i = 0; i < m; i++) cin >> mx[i] >> my[i];

    start = m+h, fin = m+h+1;
    for(int i = 0; i < m; i++)
    {
        Edge *e1 = new Edge(i, 1), *e2 = new Edge(start, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[start].push_back(e1);
        adj[i].push_back(e2);
    }
    for(int hole = 0; hole < h; hole++)
    {
        for(int mouse = 0; mouse < m; mouse++)
        {
            bool possible = true;
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                int x1 = x[i], y1 = y[i], x2 = x[(i+1)%n], y2 = y[(i+1)%n];
                if(check_same(hx[hole], hy[hole], x1, y1) || check_same(hx[hole], hy[hole], x2, y2)) continue;
                if(!check(x1, y1, x2, y2, hole, mouse)) cnt++;
                if(cnt == 2)
                {
                    possible = false;
                    break;
                }
            }
            if(!possible) continue;

            Edge *e1 = new Edge(m+hole, 1), *e2 = new Edge(mouse, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[mouse].push_back(e1);
            adj[m+hole].push_back(e2);
        }
    }
    for(int i = m; i < m+h; i++)
    {
        Edge *e1 = new Edge(fin, k), *e2 = new Edge(i, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[i].push_back(e1);
        adj[fin].push_back(e2);
    }

    int MF = 0;
    while(bfs())
    {
        memset(used, 0, sizeof(used));
        while(1)
        {
            int flow = dfs(start, fin, 1e9);
            if(!flow) break;
            MF += flow;
        }
    }
    if(MF == m) cout << "Possible";
    else cout << "Impossible";

    return 0;
}
