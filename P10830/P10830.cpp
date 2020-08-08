#include <iostream>
#include <algorithm>
#include <cmath>
#define MOD 1000
using namespace std;

typedef long long ll;

ll n, b, mat[6][6], temp[6][6], ret[6][6], binary[37], arr3[6][6];


void cross(ll arr1[][6], ll arr2[][6])
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            arr3[i][j] = 0;
            for(int k = 1; k <= n; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
                arr3[i][j] %= 1000;
            }
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            arr1[i][j] = arr3[i][j];
}

int main()
{
    scanf("%lld%lld", &n, &b);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf("%lld", &mat[i][j]);
            ret[i][j] = mat[i][j];
        }

    ll t = b-1;
    for(int i = 36; i >= 0; i--)
    {
        ll x = (ll)pow(2, i);
        while(1)
        {
            if(x <= t)
            {
                binary[i] += t/x;
                t %= x;
            }
            else break;
        }

        if(t == 0) break;
    }

    for(int i = 36; i >= 0; i--)
    {
        if(binary[i] != 0)
        {
            for(; binary[i] > 0; binary[i]--)
            {
                for(int j = 1; j <= n; j++)
                    for(int k = 1; k <= n; k++)
                        temp[j][k] = mat[j][k];

                for(int j = 0; j < i; j++)
                    cross(temp, temp);

                cross(ret, temp);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%lld ", ret[i][j]%1000);

        puts("");
    }

    return 0;
}
