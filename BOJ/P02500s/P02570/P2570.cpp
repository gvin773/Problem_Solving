#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, m, x, y, r[100][100], c[100][100], cnt1, cnt2, match, A[2020], B[2020];
vector<int> Edge[2020];
bool visited[2020];
unordered_set<int> s[2020];

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
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        s[x-1].insert(y-1);
    }
    x = 0;
    while(x < n)
    {
        for(int i = 0, j = x; i <= x && j >= 0; i++, j--)
        {
            if(s[i].find(j) != s[i].end()) cnt1++;
            r[i][j] = cnt1;
        }
        cnt1++;
        for(int i = n-1, j = n-1-x; i >= n-1-x && j <= n-1; i--, j++)
        {
            if(s[i].find(j) != s[i].end()) cnt1++;
            r[i][j] = cnt1;
        }
        cnt1++;
        x++;
    }
    x = n-1;
    while(x >= 0)
    {
        for(int i = 0, j = x; i <= n-1-x && j <= n-1; i++, j++)
        {
            if(s[i].find(j) != s[i].end()) cnt2++;
            c[i][j] = cnt2;
        }
        cnt2++;
        for(int i = x, j = 0; i <= n-1 && j <= n-1-x; i++, j++)
        {
            if(s[i].find(j) != s[i].end()) cnt2++;
            c[i][j] = cnt2;
        }
        cnt2++;
        x--;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s[i].find(j) != s[i].end()) continue;
            Edge[r[i][j]].push_back(c[i][j]);
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for(int i = 0; i < cnt1; i++)
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
