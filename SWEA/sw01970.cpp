#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a[8] = {10, 50, 100, 500, 1000, 5000, 10000, 50000}, t, n;

int main()
{
    onlycc;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n;
        int num[8] = {}, temp = n;
        for(int x = 7; x >= 0; x--)
        {
            if(a[x] <= temp)
            {
                num[x] += (temp/a[x]);
                temp %= a[x];
            }
        }
        cout << '#' << i << '\n';
        for(int x = 7; x >= 0; x--) cout << num[x] << ' ';
        cout << '\n';
    }


    return 0;
}
