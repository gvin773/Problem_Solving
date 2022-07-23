#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, k, m, p, a, b, indegree[1000], ret[1000], num[1000];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        vector<ll> edge[1000];
        queue<ll> q;
        memset(indegree, 0, sizeof(indegree));
        memset(ret, 0, sizeof(ret));
        memset(num, 0, sizeof(num));
        cin >> k >> m >> p;
        for(int i = 0; i < p; i++)
        {
            cin >> a >> b;
            indegree[b-1]++;
            edge[a-1].push_back(b-1);
        }

        for(int i = 0; i < m; i++) if(!indegree[i]) {q.push(i), ret[i] = 1;}
        for(int i = 0; i < m; i++)
        {
            if(q.empty())
            {
                cout << 0;
                return 0;
            }

            ll now = q.front();
            q.pop();

            for(auto x : edge[now])
            {
                if(ret[now] > ret[x])
                {
                    ret[x] = ret[now];
                    num[x] = 1;
                }
                else if(ret[now] == ret[x]) num[x]++;
                if(--indegree[x] == 0)
                {
                    if(num[x] >= 2) ret[x]++;
                    q.push(x);
                }
            }
        }

        cout << k << ' ' << ret[m-1] << '\n';
    }

    return 0;
}
