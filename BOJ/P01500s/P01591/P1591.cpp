#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, m, a, b, edge[3000][3000], deg[3000], checked[3000], cnt;
map<vector<int>, int> H;
vector<int> iH[3000], ans;

void Euler(int now)
{
    for(int &i = checked[now]; i < cnt; i++)
    {
        if(edge[now][i])
        {
            edge[now][i]--;
            Euler(i);
        }
    }

    ans.push_back(now);
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n-m+1; i++)
    {
        vector<int> u, v;

        cin >> a;
        u.push_back(a);
        for(int j = 1; j < m-1; j++)
        {
            cin >> b;
            u.push_back(b);
            v.push_back(b);
        }
        cin >> b;
        v.push_back(b);

        if(H.find(u) == H.end())
        {
            iH[cnt] = u;
            H[u] = cnt++;
        }
        if(H.find(v) == H.end())
        {
            iH[cnt] = v;
            H[v] = cnt++;
        }
        deg[H[u]]++, deg[H[v]]--;
        edge[H[u]][H[v]]++;
    }

    int s = -1, e = -1;
    for(int i = 0; i < cnt; i++)
    {
        if(deg[i] == 1) s = i;
        if(deg[i] == -1) e = i;
    }
    if(s != -1 && e != -1) edge[e][s]++;

    Euler(s == -1 ? 0 : s);
    reverse(ans.begin(), ans.end());
    if(s == -1)
    {
        for(int i = 0; i < iH[ans.front()].size()-1; i++) cout << iH[ans.front()][i] << ' ';
        for(auto x : ans) cout << iH[x].back() << ' ';
    }
    else
    {
        vector<int> ans2;
        for(int i = 0; i < ans.size()-1; i++)
        {
            if(ans[i] == e && ans[i+1] == s)
            {
                for(int j = i+1; j < ans.size(); j++) ans2.push_back(ans[j]);
                for(int j = 1; j <= i; j++) ans2.push_back(ans[j]);
                break;
            }
        }
        for(auto x : iH[ans2.front()]) cout << x << ' ';
        for(int i = 1; i < ans2.size(); i++) cout << iH[ans2[i]].back() << ' ';
    }

    return 0;
}
