#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 101010;
ll n, m, a, b, c, p[SIZE][20], depth[SIZE], dist[SIZE][20], query;
vector<pii> Edge[SIZE];

void init(int now)
{
    for(auto next : Edge[now])
    {
        if(depth[next.first] == -1)
        {
            depth[next.first] = depth[now] + 1;
            p[next.first][0] = now;
            dist[next.first][0] = next.second;
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
    memset(dist, 0, sizeof(dist));
    depth[1] = 0;
    init(1);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(p[j][i] == -1) continue;
            p[j][i+1] = p[p[j][i]][i];
            dist[j][i+1] = dist[j][i] + dist[p[j][i]][i];
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> query >> a >> b;
        if(query == 2) cin >> c;
        int oa = a, ob = b;

        int diff = depth[a] - depth[b];
        bool rev = false;
        if(diff < 0) swap(a, b), diff *= (-1), rev = true;

        ll cnt1 = 0, cnt2 = 0, L = 0, R = 0;
        for(int j = 0; diff; j++)
        {
            if(diff&1) L += pow(2, j), cnt1 += dist[a][j], a = p[a][j];
            diff >>= 1;
        }

        if(a != b)
        {
            for(int j = 19; j >= 0; j--)
            {
                if(p[a][j] != -1 && p[b][j] != -1 && p[a][j] != p[b][j])
                {
                    cnt1 += dist[a][j];
                    cnt2 += dist[b][j];
                    L += pow(2, j), R += pow(2, j);
                    a = p[a][j];
                    b = p[b][j];
                }
            }

            cnt1 += dist[a][0];
            cnt2 += dist[b][0];
            L++, R++;
            a = p[a][0];
        }

        if(query == 1) cout << cnt1+cnt2 << '\n';
        else
        {
            if(rev) swap(L, R);

            int up;
            if(c <= L+1) up = c-1;
            else up = R+1 - (c-L-1)-1;
            for(int j = 0; up; j++)
            {
                if(c <= L+1 && (up&1)) oa = p[oa][j];
                if(c > L+1 && (up&1)) ob = p[ob][j];
                up >>= 1;
            }

            cout << (c <= L+1 ? oa : ob) << '\n';
        }
    }

    return 0;
}
