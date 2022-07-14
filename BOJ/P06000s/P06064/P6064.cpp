#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tc, m, n, x, y, M, temp;

int gcd(int a, int b)
{
    if(a < b) swap(a, b);
    while(b)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> m >> n >> x >> y;
        M = m*n/gcd(m, n);

        for(int i = x; i <= M; i+=m)
        {
            int temp = (i%n == 0 ? n : i%n);
            if(temp == y)
            {
                cout << i << '\n';
                goto xy;
            }
        }
        cout << -1 << '\n';
        xy:;
    }

    return 0;
}
