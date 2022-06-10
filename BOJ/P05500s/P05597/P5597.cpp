#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
set<ll> s;

int main()
{
    onlycc;
    for(int i = 1; i <= 30; i++) s.insert(i);
    for(int i = 0; i < 28; i++)
    {
        cin >> n;
        s.erase(n);
    }
    for(auto i : s) cout << i << '\n';

    return 0;
}
