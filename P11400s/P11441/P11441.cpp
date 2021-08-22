#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, x, y, pSum[100001];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        pSum[i] = pSum[i-1] + x;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        cout << pSum[y] - pSum[x-1] << '\n';
    }

    return 0;
}
