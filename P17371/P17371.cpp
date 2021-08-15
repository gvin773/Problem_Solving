#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, x[1000], y[1000], ans, d = 987654321;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)
    {
        ll dis = 0;
        for(int j = 0; j < n; j++)
            if(i != j) dis =
                max(dis, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        if(dis < d)
        {
            ans = i;
            d = dis;
        }
    }

    cout << x[ans] << ' ' << y[ans];

    return 0;
}
