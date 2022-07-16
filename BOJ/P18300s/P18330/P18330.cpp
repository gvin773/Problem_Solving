#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, k;

int main()
{
    onlycc;
    cin >> n >> k;
    cout << (n <= k+60 ? 1500*n : 1500*(k+60) + 3000*(n-k-60));
    return 0;
}
