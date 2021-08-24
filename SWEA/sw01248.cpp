#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int t, v, e, a, b, p, c;

int get_size(int idx, vector<int> E_ptoc[20000])
{
    int ans = E_ptoc[idx].size();
    for(int i : E_ptoc[idx]) ans += get_size(i, E_ptoc);
    return ans;
}

void get_LCA(int y, map<int, int> &m, vector<int> E[20000], int& LCA)
{
    if(m.find(y) != m.end())
    {
        LCA = y;
        return;
    }

    for(int i : E[y])
        get_LCA(i, m, E, LCA);
}

void count_a(int now, map<int, int> &AP, vector<int> E[20000], int cnt)
{
    for(int i : E[now])
    {
        AP[i] = cnt++;
        count_a(i, AP, E, cnt);
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        vector<int> E_ptoc[20000], E_ctop[20000];
        cin >> v >> e >> a >> b;
        for(int j = 0; j < e; j++)
        {
            cin >> p >> c;
            E_ptoc[p].push_back(c);
            E_ctop[c].push_back(p);
        }

        map<int, int> a_parents;
        count_a(a, a_parents, E_ctop, 0);

        int LCA = 987654321;
        get_LCA(b, a_parents, E_ctop, LCA);
        cout << '#' << i << ' ' << LCA << ' ' << get_size(LCA, E_ptoc)+1 << '\n';
    }

    return 0;
}
