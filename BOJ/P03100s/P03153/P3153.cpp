#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int r, s, clkcnt, clk[10000], sccn[10000], SN, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, D[10000];
vector<int> edge[10000];
stack<int> S;
bool finished[10000];
string MAP[100];
vector<pii> tower, clone, scc;
unordered_map<int, int> pos_to_idx;

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
        while(1)
        {
            int x = S.top();
            S.pop();
            sccn[x] = SN;
            finished[x] = true;

            if(now == x) break;
        }
        SN++;
    }

    return ret;
}

inline void OR(int A, int B)
{
    edge[A&1 ? A-1 : A+1].push_back(B);
    if(A != B) edge[B&1 ? B-1 : B+1].push_back(A);
}

int main()
{
    onlycc;
    cin >> r >> s;
    for(int i = 0; i < r; i++)
    {
        cin >> MAP[i];
        for(int j = 0; j < s; j++)
        {
            if(MAP[i][j] == 'T') tower.push_back({i, j});
            if(MAP[i][j] == 'n') clone.push_back({i, j});
        }
    }

    for(int now = 0; now < tower.size(); now++)
    {
        int nx = tower[now].first, ny = tower[now].second;
        pos_to_idx[nx*s+ny] = now;
        for(int i = 0; i < 4; i++)
        {
            int x = nx+dx[i], y = ny+dy[i];
            while(0 <= x && x < r && 0 <= y && y < s && MAP[x][y] != '#')
            {
                if(MAP[x][y] == 'T')
                {
                    int idx = now*4+i;
                    OR(idx&1 ? idx-1 : idx+1, idx&1 ? idx-1 : idx+1);
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }
    }

    for(int now = 0; now < clone.size(); now++)
    {
        int nx = clone[now].first, ny = clone[now].second;

        unordered_set<int> po;
        for(int i = 0; i < 4; i++)
        {
            int x = nx+dx[i], y = ny+dy[i];
            while(0 <= x && x < r && 0 <= y && y < s && MAP[x][y] != '#')
            {
                if(MAP[x][y] == 'T')
                {
                    po.insert(i);
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }

        if(po.size() == 1)
        {
            int p = *po.begin();
            int x = nx+dx[p], y = ny+dy[p];
            while(0 <= x && x < r && 0 <= y && y < s && MAP[x][y] != '#')
            {
                if(MAP[x][y] == 'T')
                {
                    int idx = pos_to_idx[x*s+y]*4 + (p&1 ? p-1 : p+1);
                    OR(idx, idx);
                    break;
                }
                x += dx[p];
                y += dy[p];
            }
        }
        else if(po.size() == 2)
        {
            vector<int> idxs;
            for(auto p : po)
            {
                int x = nx+dx[p], y = ny+dy[p];
                while(0 <= x && x < r && 0 <= y && y < s && MAP[x][y] != '#')
                {
                    if(MAP[x][y] == 'T')
                    {
                        idxs.push_back(pos_to_idx[x*s+y]*4 + (p&1 ? p-1 : p+1));
                        break;
                    }
                    x += dx[p];
                    y += dy[p];
                }
            }
            OR(idxs[0], idxs[1]);
        }
        else if(po.size() == 3)
        {
            int idx[4] = {};
            memset(idx, -1, sizeof(idx));
            for(auto p : po)
            {
                int x = nx+dx[p], y = ny+dy[p];
                while(0 <= x && x < r && 0 <= y && y < s && MAP[x][y] != '#')
                {
                    if(MAP[x][y] == 'T')
                    {
                        idx[p] = pos_to_idx[x*s+y]*4;
                        break;
                    }
                    x += dx[p];
                    y += dy[p];
                }
            }

            for(int i = 0; i < 4 ;i++)
            {
                if(idx[i] == -1)
                {
                    int I = idx[i&1 ? i-1 : i+1] + i;
                    OR(I, I);
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 4*tower.size(); i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < 4*tower.size(); i++) scc.push_back({sccn[i], i});
    sort(scc.begin(), scc.end());

    memset(D, -1, sizeof(D));
    for(int i = scc.size()-1; i >= 0; i--) if(D[scc[i].second/2] == -1) D[scc[i].second/2] = !(scc[i].second & 1);

    for(int now = 0; now < tower.size(); now++)
    {
        int nx = tower[now].first, ny = tower[now].second;
        int idx = now*2;

        if(D[idx] && D[idx+1]) MAP[nx][ny] = '4';
        else if(D[idx] && !D[idx+1]) MAP[nx][ny] = '3';
        else if(!D[idx] && D[idx+1]) MAP[nx][ny] = '1';
        else MAP[nx][ny] = '2';
    }

    for(int i = 0; i < r; i++) cout << MAP[i] << '\n';

    return 0;
}
