#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, k, x, y, match, A[2020], B[2020];
vector<int> Edge[2020];
bool visited[2020];

bool dfs(int now)
{
    visited[now] = true;
    for(auto next : Edge[now])
    {
        if(B[next] == -1 || (!visited[B[next]] && dfs(B[next])))
        {
            A[now] = next;
            B[next] = now;
            return true;
        }
    }

    return false;
}

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        Edge[x-1].push_back(y-1);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for(int i = 0; i < n; i++)
    {
        if(A[i] == -1)
        {
            memset(visited, 0, sizeof(visited));
            if(dfs(i)) match++;
        }
    }
    cout << match;

    return 0;
}
