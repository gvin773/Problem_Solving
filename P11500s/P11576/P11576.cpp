#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int a, b, m, num[25], dig10, ret[1000];

int main()
{
    onlycc;
    cin >> a >> b >> m;
    for(int i = 0; i < m; i++)
        cin >> num[i];

    int cnt = 0;
    for(int i = m-1; i >= 0; i--)
        dig10 += (int)pow(a, cnt++) * num[i];

    cnt = 0;
    while(dig10)
    {
        ret[cnt++] = dig10 % b;
        dig10 /= b;
    }

    for(int i = cnt-1; i >= 0; i--)
    {
        cout << ret[i] << ' ';
    }

    return 0;
}
