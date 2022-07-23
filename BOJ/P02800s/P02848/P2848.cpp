#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, M, num, indegree[1111];
vector<ll> edge[1111], ans;
queue<ll> q;
string s[100];
unordered_map<char, int> f;
unordered_map<int, char> rf;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        M = max(M, (ll)s[i].size());
        for(auto x : s[i]) if(f.find(x) == f.end()) rf[num] = x, f[x] = num++;
    }

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(s[i].size() < s[j].size() && s[i] == s[j].substr(0, s[i].size()))
            {
                cout << '!';
                return 0;
            }
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int l = j+1; l < n; l++)
            {
                if(i < s[j].size() && i < s[l].size() && s[j][i] != s[l][i] && s[j].substr(0, i) == s[l].substr(0, i))
                {
                    indegree[f[s[l][i]]]++;
                    edge[f[s[j][i]]].push_back(f[s[l][i]]);
                }
            }
        }
    }

    for(int i = 0; i < num; i++) if(!indegree[i]) q.push(i);
    for(int i = 0; i < num; i++)
    {
        if(q.empty())
        {
            cout << '!';
            return 0;
        }
        if(q.size() > 1)
        {
            cout << '?';
            return 0;
        }

        ll now = q.front();
        q.pop();
        ans.push_back(now);

        for(auto x : edge[now]) if(--indegree[x] == 0) q.push(x);
    }

    for(auto x : ans) cout << rf[x];

    return 0;
}
