#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, a[100], o[4], M = -4646464646, m = 4646464646, ret;

void track(int now)
{
    if(now == n)
    {
        M = max(M, ret);
        m = min(m, ret);
        return;
    }

    if(o[0] > 0)
    {
        o[0]--;
        ret += a[now];
        track(now+1);

        o[0]++;
        ret -= a[now];
    }

    if(o[1] > 0)
    {
        o[1]--;
        ret -= a[now];
        track(now+1);

        o[1]++;
        ret += a[now];
    }

    if(o[2] > 0)
    {
        o[2]--;
        ret *= a[now];
        track(now+1);

        o[2]++;
        ret /= a[now];
    }

    if(o[3] > 0)
    {
        o[3]--;
        int temp = ret;
        ret /= a[now];
        track(now+1);

        o[3]++;
        ret = temp;
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) cin >> o[i];
    ret = a[0];
    track(1);
    cout << M << '\n' << m;

    return 0;
}
