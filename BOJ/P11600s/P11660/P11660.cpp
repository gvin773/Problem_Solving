#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, x, y, x2, y2, pSum[1025][1025];

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> x;
            pSum[i][j] = pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1] + x;
        }
    }

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> x2 >> y2;
        cout << pSum[x2][y2] - pSum[x2][y-1] - pSum[x-1][y2] + pSum[x-1][y-1] << '\n';
    }

    return 0;
}
