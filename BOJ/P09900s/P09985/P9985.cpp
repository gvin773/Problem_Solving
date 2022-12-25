#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll d, n, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ans = LLONG_MAX;
string dummy, x;
pll start, fin;
vector<string> vs, vf;
queue<pll> q;
queue<vector<string>> qv;
map<vector<string>, ll> ms ,mf;

int main()
{
    onlycc;
    while(cin >> dummy)
    {
        ans = LLONG_MAX;
        vs.clear();
        vf.clear();
        while(!q.empty()) q.pop();
        while(!qv.empty()) qv.pop();
        ms.clear();
        mf.clear();

        cin >> d >> n;
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                cin >> x;
                vs.push_back(x);
                if(x == "X")
                {
                    start.first = i;
                    start.second = j;
                }
            }
        }
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                cin >> x;
                vf.push_back(x);
                if(x == "X")
                {
                    fin.first = i;
                    fin.second = j;
                }
            }
        }
        cin >> dummy;

        q.push(start);
        qv.push(vs);
        ms[vs] = 0;
        for(int z = 0; z < n/2; z++)
        {
            int Size = q.size();
            for(int zz = 0; zz < Size; zz++)
            {
                auto now = q.front();
                q.pop();
                auto v = qv.front();
                qv.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nx = now.first+dx[i], ny = now.second+dy[i];
                    if(nx < 0 || nx >= d || ny < 0 || ny >= d) continue;

                    swap(v[now.first*d+now.second], v[nx*d+ny]);
                    if(ms.find(v) == ms.end())
                    {
                        ms[v] = z+1;
                        q.push({nx, ny});
                        qv.push(v);
                    }
                    swap(v[now.first*d+now.second], v[nx*d+ny]);
                }
            }
        }

        while(!q.empty()) q.pop();
        while(!qv.empty()) qv.pop();

        q.push(fin);
        qv.push(vf);
        mf[vf] = 0;
        for(int z = 0; z < n/2 + (n&1); z++)
        {
            int Size = q.size();
            for(int zz = 0; zz < Size; zz++)
            {
                auto now = q.front();
                q.pop();
                auto v = qv.front();
                qv.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nx = now.first+dx[i], ny = now.second+dy[i];
                    if(nx < 0 || nx >= d || ny < 0 || ny >= d) continue;

                    swap(v[now.first*d+now.second], v[nx*d+ny]);
                    if(mf.find(v) == mf.end())
                    {
                        mf[v] = z+1;
                        q.push({nx, ny});
                        qv.push(v);
                    }
                    swap(v[now.first*d+now.second], v[nx*d+ny]);
                }
            }
        }

        for(auto froms : ms)
        {
            auto fromf = mf.find(froms.first);
            if(fromf != mf.end())
            {
                ans = min(ans, froms.second + fromf->second);
            }
        }
        if(ans == LLONG_MAX) cout << "NOT SOLVABLE WITHIN " << n << " MOVES\n";
        else cout << "SOLVABLE WITHIN " << ans << " MOVES\n";
        cout << '\n';
    }

    return 0;
}
