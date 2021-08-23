#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, k, team, leftt;

int main()
{
    onlycc;
    cin >> n >> m >> k;
    team = min(n/2, m);
    leftt = n+m-3*team;
    if(leftt >= k) cout << team;
    else
    {
        while(1)
        {
            leftt += 3;
            team -= 1;
            if(leftt >= k) break;
        }
        if(team > 0) cout << team;
        else cout << 0;
    }

    return 0;
}
