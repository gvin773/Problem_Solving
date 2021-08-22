#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int r, c, r2, c2, q, pSum[1001][1001];

int main()
{
    onlycc;
    cin >> r >> c >> q;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> pSum[i][j];
            pSum[i][j] += (pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1]);
        }
    }

    for(int i = 0; i < q; i++)
    {
        cin >> r >> c >> r2 >> c2;
        cout << (pSum[r2][c2] - pSum[r-1][c2] - pSum[r2][c-1] + pSum[r-1][c-1])/((r2-r+1)*(c2-c+1)) << '\n';
    }

    return 0;
}
