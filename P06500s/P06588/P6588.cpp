#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, a[1000001] = {1, 1, }, p[78500]; //78499 -> 1000003

int main()
{
    for(int i = 2; i <= 1000000; i++)
    {
        for(int j = 2; i*j <= 1000000; j++)
            a[i*j] = 1;
    }

    int cnt = 0;
    for(int i = 1; i < 1000000; i++)
        if(a[i] == 0)
            p[cnt++] = i;

    onlycc;
    while(1)
    {
        cin >> n;
        if(n == 0) return 0;

        int right = 0;
        for(int i = 1; p[i] < n; i++)
        {
            int a = p[i], b = 0, cnt = 0;
            for(int j = 0; a + p[j] <= n; j++)
            {
                if(a + p[j] == n)
                {
                    cnt = 1;
                    b = p[j];
                    break;
                }
            }

            if(cnt)
            {
                cout << n << " = " << a << " + " << b << '\n';
                right = 1;
                break;
            }
        }

        if(!right) cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
