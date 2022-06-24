#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a, b;
map<ll, ll> m;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        m[a]++;
    }
    cin >> b;
    m[b]++;
    cout << m[b]-1;

    return 0;
}
