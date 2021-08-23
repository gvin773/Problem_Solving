#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, n, num[100];

int gcd(int a, int b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        ll sum = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> num[j];

        for(int j = 0; j < n; j++)
            for(int k = j+1; k < n; k++)
                sum += gcd(max(num[j],num[k]), min(num[j],num[k]));

        cout << sum << '\n';
    }

    return 0;
}
