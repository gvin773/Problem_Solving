#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b, c, d, e, f, p[3];

int main()
{
    onlycc;
    for(int i = 0; i < 3; i++)
    {
        cin >> a >> b >> c >> d >> e >> f;
        p[i] = d*3600+e*60+f - (a*3600+b*60+c);
    }
    for(int i = 0; i < 3; i++)
        cout << p[i] / 3600 << ' ' << p[i]%3600/60 << ' ' << p[i]%60 << '\n';

    return 0;
}
