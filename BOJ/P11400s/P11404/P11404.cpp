#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m, a, b, c, d[100][100];

int main()
{
    onlycc;
    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 987654321;
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
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
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

    return 0;
}
