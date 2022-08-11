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
    int E, C, F;
    Edge* dual;

    Edge() : Edge(-1, 0){}
    Edge(int E1, int C1) : E(E1), C(C1), F(0), dual(nullptr){}

    int get_C() { return C-F; }
    void update_F(ll F1)
    {
        F += F1;
        dual->F -= F1;
    }
};

ll tc, n, a[101], ans;
string arr[100];
vector<Edge*> adj[1111];
vector<int> weak;

void add_edge(int next, int C1, int now, int C2)
{
    Edge *e1 = new Edge(next, C1), *e2 = new Edge(now, C2);
    e1->dual = e2;
    e2->dual = e1;

    adj[now].push_back(e1);
    adj[next].push_back(e2);
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ans = 0;
        for(int z = 0; z < 1111; z++) adj[z].clear();
        weak.clear();
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] == 0) continue;
            add_edge(i, a[i], 0, 0);
        }
        for(int i = 0 ; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || a[i+1] == 0 || a[j+1] == 0) continue;
                if(arr[i][j] == 'N') continue;
                add_edge(n+j+1, 1e9, i+1, 0);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i+1] == 0) continue;
            add_edge(n+i+1, 1e9, i+1, 0);
        }

        for(int i = 0; i < n; i++)
        {
            if(a[i+1] == 0) continue;
            bool flag = true;
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(arr[i][j] == 'Y' && a[j+1] == 0)
                {
                    weak.push_back(i+1);
                    flag = false;
                    break;
                }
            }
            if(flag) add_edge(n+n+1, 1, n+i+1, 0);
        }

        int lo = 0, hi = 1e9, sum = 0;
        for(int i = 1; i <= n; i++) if(a[i] != 0) sum++;
        while(lo+1 < hi)
        {
            int mid = (lo+hi) / 2;
            for(int i = 0; i < n+n+1; i++) for(auto e : adj[i]) e->F = 0;
            for(auto now : weak) add_edge(n+n+1, mid, n+now, 0);

            int ans = 0;
            while(1)
            {
                int prev[1111];
                memset(prev, -1, sizeof(prev));
                Edge *path[1111];
                queue<int> q;

                q.push(0);
                while(!q.empty() && prev[n+n+1] == -1)
                {
                    int now = q.front();
                    q.pop();

                    for(auto e : adj[now])
                    {
                        int next = e->E;
                        if(e->get_C() > 0 && prev[next] == -1)
                        {
                            q.push(next);
                            prev[next] = now;
                            path[next] = e;
                            if(next == n+n+1) break;
                        }
                    }
                }
                if(prev[n+n+1] == -1) break;

                int flow = 1e9;
                for(int i = n+n+1; i != 0; i = prev[i]) flow = min(flow, path[i]->get_C());
                for(int i = n+n+1; i != 0; i = prev[i]) path[i]->update_F(flow);
                ans += flow;
            }

            if(ans == weak.size() * mid + sum - weak.size()) lo = mid;
            else hi = mid;

            for(auto now : weak)
            {
                adj[n+now].pop_back();
                adj[n+n+1].pop_back();
            }
        }

        cout << lo << '\n';
    }

    return 0;
}
