#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, road[100000], oil[100000], ans;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n-1; i++) cin >> road[i];
    for(int i = 0; i < n; i++) cin >> oil[i];
    for(int now = 0; now < n; now++)
    {
        ans += road[now]*oil[now];
        for(int next = now+1; next < n; next++)
        {
            if(next == n-1)
            {
                cout << ans;
                return 0;
            }
            if(oil[now] <= oil[next]) ans += road[next]*oil[now];
            else
            {
                now = next-1;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
