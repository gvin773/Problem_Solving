#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    cout << a * max(b, c) / min(b, c);

    return 0;
}
