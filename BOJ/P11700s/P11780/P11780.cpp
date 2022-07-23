#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, a, b, c, d[100][100], logs[100][100];
deque<ll> q;

void track(int s, int e)
{
    if(logs[s][e] == -1)
    {
        q.push_back(s);
        q.push_back(e);
        return;
    }

    track(s, logs[s][e]);
    q.pop_back();
    track(logs[s][e], e);
}

int main()
{
    onlycc;
    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 987654321;
    memset(logs, -1, sizeof(logs));
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        d[a-1][b-1] = min(d[a-1][b-1], c);
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    logs[i][j] = k;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) cout << 0 << ' ';
            else cout << (d[i][j] == 987654321 ? 0 : d[i][j]) << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || d[i][j] == 987654321)
            {
                cout << 0 << '\n';
                continue;
            }

            track(i, j);
            cout << q.size() << ' ';
            while(!q.empty())
            {
                cout << q.front()+1 << ' ';
                q.pop_front();
            }
            cout << '\n';
        }
    }

    return 0;
}
