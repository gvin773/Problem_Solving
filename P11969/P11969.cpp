#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n, q, x, y, pSum[4][100001];

int main()
{
    onlycc;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        pSum[1][i] = pSum[1][i-1] + (x == 1 ? 1 : 0);
        pSum[2][i] = pSum[2][i-1] + (x == 2 ? 1 : 0);
        pSum[3][i] = pSum[3][i-1] + (x == 3 ? 1 : 0);
    }
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        cout << pSum[1][y] - pSum[1][x-1] << ' '
             << pSum[2][y] - pSum[2][x-1] << ' '
             << pSum[3][y] - pSum[3][x-1] << '\n';
    }

    return 0;
}
