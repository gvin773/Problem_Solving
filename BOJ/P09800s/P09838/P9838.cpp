#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, a[20001], x;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    for(int i = 1; i<= n; i++) cout << a[i] << '\n';

    return 0;
}
