#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, a, b, c, L[10001], R[10001], root, idx[10001], level[10001], nowidx, M[10001], m[10001], ans, w = -1;
bool root_check[10001];

void dfs(int now, int nowlevel)
{
    if(now == -1) return;

    dfs(L[now], nowlevel+1);

    idx[now] = ++nowidx;
    level[now] = nowlevel;

    dfs(R[now], nowlevel+1);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        L[a] = b, R[a] = c;
    }

    for(int i = 1; i <= n; i++)
    {
        if(L[i] != -1) root_check[L[i]] = true;
        if(R[i] != -1) root_check[R[i]] = true;
    }
    for(int i = 1; i <= n; i++) if(!root_check[i]) root = i;
    dfs(root, 1);

    for(int i = 1; i <= n; i++) M[i] = -1, m[i] = 987654321;
    for(int i = 1; i <= n; i++)
    {
        M[level[i]] = max(M[level[i]], idx[i]);
        m[level[i]] = min(m[level[i]], idx[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        if(M[i] == -1 && m[i] == 987654321) continue;
        if((M[i] == -1 || m[i] == 987654321) && (1 > w)) w = 1, ans = i;
        else if(M[i]-m[i]+1 > w)
        {
            w = M[i]-m[i]+1;
            ans = i;
        }
    }
    cout << ans << ' ' << w;

    return 0;
}
