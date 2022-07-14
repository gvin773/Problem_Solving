#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, f[50];

ll fibonacci(ll n)
{
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++) f[i] = f[i-1] + f[i-2];
    return f[n];
}

int main()
{
    onlycc;
    cin >> n;
    cout << fibonacci(n) << ' ' << n-2;

    return 0;
}
