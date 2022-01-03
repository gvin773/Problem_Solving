#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int a, d, k, cnt;
long double p[100000], pi = 1, ans;

int main()
{
    onlycc;
    cin >> a >> d >> k;
    for(int i = 1; ; i++)
    {
        p[i] = 0.01*d*pow(1+0.01*k, i-1);
        if(p[i] >= 1)
        {
            p[i] = 1;
            cnt = i;
            break;
        }
    }

    for(int i = 1; i <= cnt; i++)
    {
        pi = 1;
        for(int j = 1; j < i; j++) pi *= (1-p[j]);
        pi *= p[i];
        ans += pi*i;
    }

    cout.precision(12);
    cout << ans*a;

    return 0;
}
