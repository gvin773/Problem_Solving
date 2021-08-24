#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, n;
long double pos[10], m[10], ans[10];

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> pos[i];
        for(int i = 0; i < n; i++) cin >> m[i];

        for(int i = 0; i < n-1; i++)
        {
            long double lo = pos[i], hi = pos[i+1];
            for(int iter = 0; iter < 100; iter++)
            {
                long double mid = (lo+hi) / 2, eq = 0;
                for(int j = 0; j <= i; j++) eq += m[j]/(mid-pos[j])/(mid-pos[j]);
                for(int j = i+1; j < n; j++) eq -= m[j]/(mid-pos[j])/(mid-pos[j]);

                if(eq > 0) lo = mid;
                else
                {
                    ans[i] = mid;
                    hi = mid;
                }
            }
        }

        cout << fixed;
        cout.precision(10);
        cout << '#' << tc << ' ';
        for(int i = 0; i < n-1; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
