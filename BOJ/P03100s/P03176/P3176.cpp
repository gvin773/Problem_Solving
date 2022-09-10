#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 101010;
ll n, k, a, b, c, p[SIZE][20], depth[SIZE], m[SIZE][20], M[SIZE][20], mans, Mans;
vector<pii> Edge[SIZE];

void init(int now)
{
    for(auto next : Edge[now])
    {
        if(depth[next.first] == -1)
        {
            depth[next.first] = depth[now] + 1;
            p[next.first][0] = now;
            m[next.first][0] = next.second;
            M[next.first][0] = next.second;
            init(next.first);
        }
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        Edge[a].push_back({b, c});
        Edge[b].push_back({a, c});
    }

    memset(p, -1, sizeof(p));
    memset(depth, -1, sizeof(depth));
    memset(M, -1, sizeof(M));
    for(int i = 0; i < SIZE; i++) for(int j = 0; j < 20; j++) m[i][j] = 987654321;
    depth[1] = 0;
    init(1);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(p[j][i] == -1) continue;
            p[j][i+1] = p[p[j][i]][i];
            m[j][i+1] = min(m[j][i], m[p[j][i]][i]);
            M[j][i+1] = max(M[j][i], M[p[j][i]][i]);
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> a >> b;

        mans = 987654321, Mans = -1;
        int diff = depth[a] - depth[b];
        if(diff < 0) swap(a, b), diff *= (-1);

        for(int j = 0; diff; j++)
        {
            if(diff&1) mans = min(mans, m[a][j]), Mans = max(Mans, M[a][j]), a = p[a][j];
            diff >>= 1;
        }

        if(a != b)
        {
            for(int j = 19; j >= 0; j--)
            {
                if(p[a][j] != -1 && p[b][j] != -1 && p[a][j] != p[b][j])
                {
                    mans = min({mans, m[a][j], m[b][j]});
                    Mans = max({Mans, M[a][j], M[b][j]});
                    a = p[a][j];
                    b = p[b][j];
                }
            }

            mans = min({mans, m[a][0], m[b][0]});
            Mans = max({Mans, M[a][0], M[b][0]});
            a = p[a][0];
        }

        cout << mans << ' ' << Mans << '\n';
    }

    return 0;
}
