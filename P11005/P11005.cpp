#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a[50], cnt = 0;

int main()
{
    onlycc;
    int n, b;
    cin >> n >> b;

    while(n)
    {
        a[cnt++] = n % b;
        n /= b;
    }

    for(int i = 0; i < cnt; i++)
    {
        if(a[i] >= 10)
        {
            a[i] = a[i] - 10 + 'A';
        }
    }

    for(int i = cnt-1; i >= 0; i--)
    {
        if(0 <= a[i] && a[i] <= 9)
            cout << a[i];

        else cout << (char)a[i];
    }

    return 0;
}
