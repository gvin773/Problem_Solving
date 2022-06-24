#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a, b, ans[100001];
vector<int> v[100001];
bool visited[100001];
queue<int> q;

void get_ans()
{
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < v[now].size(); i++)
        {
            if(!visited[v[now][i]])
            {
                ans[v[now][i]] = now;
                visited[v[now][i]] = true;
                q.push(v[now][i]);
            }
        }
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    get_ans();
    for(int i = 2; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}
