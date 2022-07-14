#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, k, psum[100001], M = -987654321;

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> psum[i];
        psum[i] += psum[i-1];
    }
    for(int i = 0; i+k <= n; i++) M = max(M, psum[i+k]-psum[i]);
    cout << M;

    return 0;
}
