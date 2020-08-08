#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, k, mat1[101][101], mat2[101][101], mat3[101][101];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &mat1[i][j]);

    scanf("%d%d", &m, &k);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= k; j++)
            scanf("%d", &mat2[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            for(int x = 1; x <= m; x++)
                mat3[i][j] += mat1[i][x]*mat2[x][j];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
            printf("%d ", mat3[i][j]);

        puts("");
    }

    return 0;
}
