#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, ans;
string s;

int main()
{
    onlycc;
    cin >> n >> m >> s;
    for(int i = 0; i < m-2; i++)
    {
        if(s[i] == 'I')
        {
            int k = 0;
            for(; i < m-2; i += 2)
            {
                if(s[i+1] == 'O' && s[i+2] == 'I') k++;
                else break;

                if(k >= n) ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
