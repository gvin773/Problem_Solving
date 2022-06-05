#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, a[100][100], b, c[100][100];

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> b;
            c[i][j] = a[i][j] + b;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cout << c[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
