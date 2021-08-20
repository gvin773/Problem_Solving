#include <cstdio>
#include <algorithm>
using namespace std;

char board[9][9];
char bigboard[51][51];

int check()
{
    int counter = 0;

    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(i%2 == 1 && j%2 == 1) //White when i, j == odd
            {
                if(board[i][j] != 'W') counter++;
            }

            else if(i%2 == 1 && j%2 == 0) //Black when i == odd, j == even
            {
                if(board[i][j] != 'B') counter++;
            }

            else if(i%2 == 0 && j%2 == 1) //Black when i == even, j == odd
            {
                if(board[i][j] != 'B') counter++;
            }

            else if(i%2 == 0 && j%2 == 0) //White when i, j == even
            {
                if(board[i][j] != 'W') counter++;
            }
        }
    }

    return min(counter, 64-counter);
}

int main()
{
    int n, m, ret = 987654321;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf(" %c", &bigboard[i][j]);

    for(int i = 1; i+7 <= n; i++)
        for(int j = 1; j+7 <= m; j++)
        {
            for(int k = 1; k <= 8; k++)
                for(int l = 1; l <= 8; l++)
                    board[k][l] = bigboard[i+k-1][l+j-1];

            ret = min(ret, check());
        }

    printf("%d", ret);

    return 0;
}
