#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, a[100][100], b[100][100], c1, c2, match, A[10100], B[10100];
vector<int> Edge[10100];
bool visited[10100];
string board[100];

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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 'X') c1++;
            a[i][j] = c1;
        }
        c1++;
    }
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(board[i][j] == 'X') c2++;
            b[i][j] = c2;
        }
        c2++;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 'X') continue;
            Edge[a[i][j]].push_back(b[i][j]);
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    for(int i = 0; i <= c1; i++)
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
