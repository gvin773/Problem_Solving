#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

ll a, b, cnt;
bool prime[10000001];

int main()
{
    onlycc;
    cin >> a >> b;
    for(int i = 2; i <= 10000000; i++)
        for(int j = 2; i*j <= 10000000; j++)
            prime[i*j] = true;

    for(int i = 2; i <= 10000000; i++)
    {
        if(!prime[i])
        {
            int temp = i;
            for(ll j = i; j <= b/i; j *= i)
            {
                if(a <= j*i) cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
