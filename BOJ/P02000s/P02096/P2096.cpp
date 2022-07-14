#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a, b, c, m[3], M[3], t[3];

int main()
{
    onlycc;
    cin >> n;
    cin >> a >> b >> c;
    M[0] = m[0] = a;
    M[1] = m[1] = b;
    M[2] = m[2] = c;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        t[0] = min(m[0]+a,m[1]+a);
        t[1] = min(min(m[0]+b,m[1]+b),m[2]+b);
        t[2] = min(m[1]+c,m[2]+c);
        for(int i = 0; i < 3; i++) m[i] = t[i];

        t[0] = max(M[0]+a,M[1]+a);
        t[1] = max(max(M[0]+b,M[1]+b),M[2]+b);
        t[2] = max(M[1]+c,M[2]+c);
        for(int i = 0; i < 3; i++) M[i] = t[i];
    }

    sort(m, m+3);
    sort(M, M+3);
    cout << M[2] << ' ' << m[0];

    return 0;
}
