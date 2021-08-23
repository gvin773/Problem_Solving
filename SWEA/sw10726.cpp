#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int tc, n, m;

int main()
{
    onlycc;
    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        cin >> n >> m;
        bool ans = true;

        while(n--)
        {
            int x = m % 2;
            if(x == 0)
            {
                ans = false;
                break;
            }
            m /= 2;
        }

        cout << "#" << i+1 << ' ';
        if(ans) cout << "ON\n";
        else cout << "OFF\n";
    }

    return 0;
}
