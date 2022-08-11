#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, m, k, s, x, match, A[2000], B[2000];
vector<int> Edge[2000];
bool visited[2000];

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
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < s; j++)
        {
            cin >> x;
            Edge[i*2].push_back(x-1);
            Edge[i*2+1].push_back(x-1);
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for(int i = 0; i < 2*n; i+=2)
    {
        if(A[i] == -1)
        {
            memset(visited, 0, sizeof(visited));
            if(dfs(i)) match++;
        }
    }

    int match2 = 0;
    for(int i = 1; i < 2*n; i+=2)
    {
        if(A[i] == -1)
        {
            memset(visited, 0, sizeof(visited));
            if(dfs(i)) match2++;
        }
        if(match2 == k) break;
    }
    cout << match + match2;

    return 0;
}
