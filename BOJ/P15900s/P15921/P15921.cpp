#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a[150], sum;
map<ll, ll> m;
double e;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        sum += a[i];
    }
    for(auto i = m.begin(); i != m.end(); i++) e += (i->first)*(i->second)/(double)n;
    cout.precision(2);
    cout << fixed;
    if(e != 0) cout << sum / e / n;
    else cout << "divide by zero";

    return 0;
}
