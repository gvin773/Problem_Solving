#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, h, cnt[3];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> h;
        cnt[2] += (h / 2);
        cnt[1] += (h & 1);
    }

    if((2*cnt[2] + cnt[1]) % 3) cout << "NO";
    else if(cnt[2] >= cnt[1] && !((cnt[2] - cnt[1]) % 3)) cout << "YES";
    else cout << "NO";

    return 0;
}
