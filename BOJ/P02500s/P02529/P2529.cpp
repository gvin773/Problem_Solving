#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll k, indegree[10], cnt;
vector<ll> edge[10], ans(11);
priority_queue<ll> qq;
priority_queue<ll, vector<ll>, greater<ll>> q, pq;
char c[10];

int main()
{
    onlycc;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> c[i];
        if(c[i] == '>')
        {
            indegree[i+1]++;
            edge[i].push_back(i+1);
        }
        else
        {
            indegree[i]++;
            edge[i+1].push_back(i);
        }
    }

    cnt = 9;
    for(int i = 0; i < k+1; i++) if(!indegree[i]) q.push(i);
    for(int i = 0; i < k+1; i++)
    {
        if(q.empty())
        {
            cout << 0;
            return 0;
        }

        ll now = q.top();
        q.pop();
        ans[now] = cnt--;

        for(auto x : edge[now]) if(--indegree[x] == 0) q.push(x);
    }
    for(int i = 0; i < k+1; i++) cout << ans[i]; cout << '\n';

    memset(indegree, 0, sizeof(indegree));
    cnt = 0;
    for(int i = 0; i < k; i++)
    {
        if(c[i] == '<')
        {
            indegree[i+1]++;
            edge[i].push_back(i+1);
        }
        else
        {
            indegree[i]++;
            edge[i+1].push_back(i);
        }
    }

    for(int i = 0; i < k+1; i++) if(!indegree[i]) pq.push(i);
    for(int i = 0; i < k+1; i++)
    {
        if(pq.empty())
        {
            cout << 0;
            return 0;
        }

        ll now = pq.top();
        pq.pop();
        ans[now] = cnt++;

        for(auto x : edge[now]) if(--indegree[x] == 0) pq.push(x);
    }
    for(int i = 0; i < k+1; i++) cout << ans[i];

    return 0;
}
