#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int MAX = 2000;

ll n, m, k, psum[MAX][MAX], ans = LLONG_MAX;
string arr[MAX];

int main()
{
    onlycc;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i > 0) psum[i][j] += psum[i-1][j];
            if(j > 0) psum[i][j] += psum[i][j-1];
            if(i > 0 && j > 0) psum[i][j] -= psum[i-1][j-1];
            if(!((i+j)&1) && arr[i][j] == 'W') psum[i][j]++;
            if(((i+j)&1) && arr[i][j] == 'B') psum[i][j]++;
        }
    }
    for(int i = k-1; i < n; i++)
    {
        for(int j = k-1; j < m; j++)
        {
            ll ret = psum[i][j];
            if(i >= k) ret -= psum[i-k][j];
            if(j >= k) ret -= psum[i][j-k];
            if(i >= k && j >= k) ret += psum[i-k][j-k];
            ans = min(ans, min(ret, k*k-ret));
        }
    }
    cout << ans;

    return 0;
}
