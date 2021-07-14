#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, q, pSum[1000001], ans, s, e;

int main()
{
    onlycc;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> pSum[i];
        if(i != 1) pSum[i] ^= pSum[i-1];
    }

    for(int i = 0; i < q; i++)
    {
        cin >> s >> e;
        if(i == 0)
        {
            if(s != 1) ans = pSum[e] ^ pSum[s-1];
            else ans = pSum[e];
        }
        else
        {
            if(s != 1) ans ^= (pSum[e] ^ pSum[s-1]);
            else ans ^= pSum[e];
        }
    }

    cout << ans;

    return 0;
}
