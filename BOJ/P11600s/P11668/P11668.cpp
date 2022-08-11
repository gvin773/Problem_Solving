#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int W, P, x[2200], y[2200], s, a, b, clk[2200], clkcnt, sccn[2200], SN;
vector<int> edge[2200];
stack<int> S;
bool finished[2200];
vector<vector<int>> SCC;
vector<pair<pii, pii>> pipe;
unordered_set<ll> water;

int dfs(int now)
{
    clk[now] = ++clkcnt;
    S.push(now);

    int ret = clk[now];
    for(auto next : edge[now])
    {
        if(!clk[next]) ret = min(ret, dfs(next));
        else if(!finished[next]) ret = min(ret, clk[next]);
    }

    if(ret == clk[now])
    {
        vector<int> v;
        while(1)
        {
            int x = S.top();
            S.pop();
            v.push_back(x);
            sccn[x] = SN;
            finished[x] = true;

            if(now == x) break;
        }
        SN++;

        SCC.push_back(v);
    }

    return ret;
}

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    ll ret = x1*y2 - x2*y1;
    return (ret == 0 ? 0 : (ret > 0 ? 1 : -1));
}

void XOR(int a, int b)
{
    a++, b++;
    a = (a < 0 ? -(a+1)*2 : a*2-1);
    b = (b < 0 ? -(b+1)*2 : b*2-1);

    edge[a&1 ? a-1 : a+1].push_back(b);
    edge[b&1 ? b-1 : b+1].push_back(a);
    edge[a].push_back(b&1 ? b-1 : b+1);
    edge[b].push_back(a&1 ? a-1 : a+1);
}

int main()
{
    onlycc;
    cin >> W >> P;
    for(int i = 0; i < W; i++)
    {
        cin >> x[i] >> y[i];
        ll tx = x[i]+10000, ty = y[i]+10000;
        water.insert(tx*20001+ty);
    }
    for(int i = 0; i < P; i++)
    {
        cin >> s >> a >> b;
        pipe.push_back({{x[s-1], y[s-1]}, {a, b}});
    }

    for(int i = 0; i < pipe.size(); i++)
    {
        for(int j = i+1; j < pipe.size(); j++)
        {
            ll x1 = pipe[i].first.first, y1 = pipe[i].first.second, x2 = pipe[i].second.first, y2 = pipe[i].second.second;
            ll a = pipe[j].first.first, b = pipe[j].first.second, c = pipe[j].second.first, d = pipe[j].second.second;

            if(x1 == a && y1 == b) continue;
            if(x2 == c && y2 == d)
            {
                XOR(i, j);
                continue;
            }

            if(a < x1 || (a == x1 && b < y1))
            {
                swap(x1, a);
                swap(y1, b);
                swap(x2, c);
                swap(y2, d);
            }

            if(x1 == x2 && x2 == a && a == c)
            {
            	if(y2 >= b) XOR(i, j);
            	else continue;
            }
            else if(y1 == y2 && y2 == b && b == d)
            {
            	if(x2 >= a) XOR(i, j);
            	else continue;
            }
            else if((y2-y1)*(a-x2) == (b-y2)*(x2-x1) && (b-y2)*(c-a) == (d-b)*(a-x2))
            {
            	if(x2 >= a) XOR(i, j);
            	else continue;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, d-b, x1-c, y1-d) * cross(c-a, d-b, x2-c, y2-d) <= 0) XOR(i, j);
        }
    }
    for(int i = 0; i < 2*P; i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < P; i++)
    {
        if(sccn[i*2] == sccn[i*2+1])
        {
            cout << "impossible";
            return 0;
        }
    }
    cout << "possible";

    return 0;
}
