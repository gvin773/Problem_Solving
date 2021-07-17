#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n, q, x, y, pSum[1001], a[1001];

int main()
{
    onlycc;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i != 1) pSum[i] = pSum[i-1] + abs(a[i] - a[i-1]);
    }
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        cout << pSum[y] - pSum[x] << '\n';
    }

    return 0;
}
