#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;
const int RANGE = 10000000;

int k, m, Max, deg[RANGE], edge[RANGE], checked[RANGE], ans[RANGE], anscnt;
bool visited[RANGE];

int bfs(int z)
{
    int ret = 0;
    visited[z] = true;

    queue<int> q;
    q.push(z);

    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            ret++;
            int now = q.front();
            q.pop();

            ll next;
            for(int j = 0; j < k; j++)
            {
                next = 1LL * now * k;
                next += j;
                next %= Max;

                if(0 <= next && next < Max && !visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }

    return ret;
}

void Euler(int now)
{
    for(int &i = checked[now]; i < k; )
    {
        ll next = edge[(1LL * now * k + i) % Max];
        i++;
        Euler(next);
    }

    ans[anscnt--] = now;
}

int main()
{
    onlycc;
    cin >> k >> m;
    if(m == 1)
    {
        for(int i = 0; i < k; i++) cout << i << ' ';
        return 0;
    }

    Max = 1;
    for(int i = 0; i < m; i++) Max *= k;

    Max /= k;
    memset(edge, -1, sizeof(edge));
    for(int now = 0; now < Max; now++)
    {
        ll next;
        for(int j = 0; j < k; j++)
        {
            next = 1LL * now * k;
            next += j;
            next %= Max;

            deg[now]++;
            deg[next]--;
            edge[now*k+j] = next;
        }
    }

    for(int i = 0; i < Max; i++)
    {
        if(deg[i])
        {
            cout << -1;
            return 0;
        }
    }

    if(bfs(0) != Max)
    {
        cout << -1;
        return 0;
    }

    anscnt = Max*k-1;
    Euler(0);
    Max *= k;
    for(int i = 0; i < Max; i++) cout << ans[i]%k << ' ';

    return 0;
}
