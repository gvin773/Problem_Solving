#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, ret[50];

int main()
{
    onlycc;
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    while(n)
    {
        if(n > 0)
        {
            if(n % -2 == 0)
            {
                ret[cnt++] = 0;
                n /= -2;
            }

            else
            {
                ret[cnt++] = 1;
                n /= -2;
            }
        }

        else
        {
            if(n % -2 == 0)
            {
                ret[cnt++] = 0;
                n /= -2;
            }

            else
            {
                n -= 1;
                n /= -2;
                ret[cnt++] = 1;
            }
        }
    }

    for(int i = cnt-1; i >= 0; i--)
        cout << ret[i];

    return 0;
}
