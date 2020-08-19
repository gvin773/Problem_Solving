#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, mat[2][2] = {1, 1, 1, 0}, temp[2][2], ret[2][2] = {1, 1, 1, 0}, binary[60], arr3[2][2];


void cross(ll arr1[][2], ll arr2[][2], ll MOD)
{
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            arr3[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
                arr3[i][j] %= MOD;
            }
        }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            arr1[i][j] = arr3[i][j];
}

int main()
{
    scanf("%lld", &n);

    for(int num = 1; num <= n; num++)
    {
        for(int x = 0; x < 2; x++)
            for(int y = 0; y < 2; y++)
                temp[x][y] = 0;

        ret[0][0] = 1, ret[0][1] = 1, ret[1][0] = 1, ret[1][1] = 0;

        ll P, MOD;
        scanf("%lld%lld", &P, &MOD);

        ll t = P-1;
        for(int i = 59; i >= 0; i--)
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

        for(int i = 59; i >= 0; i--)
        {
            if(binary[i] != 0)
            {
                for(; binary[i] > 0; binary[i]--)
                {
                    for(int j = 0; j < 2; j++)
                        for(int k = 0; k < 2; k++)
                            temp[j][k] = mat[j][k];

                    for(int j = 0; j < i; j++)
                        cross(temp, temp, MOD);

                    cross(ret, temp, MOD);
                }
            }
        }

        printf("Case #%lld: %lld\n", num, ret[0][1] % MOD);

    }

    return 0;
}
