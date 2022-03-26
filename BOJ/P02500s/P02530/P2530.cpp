#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int time_to_sec(int h, int m, int s)
{
    return (h*60+m)*60 + s;
}

int a, b, c, d;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d;
    d += time_to_sec(a, b, c);
    cout << d/3600%24 << ' ' << d%3600/60 << ' ' << d%3600%60;

    return 0;
}
