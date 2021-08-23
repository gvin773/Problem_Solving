#include <cstdio>
#include <algorithm>
using namespace std;

char board[52][52]; //side == '\0'

int main()
{
    int n, ret = 0, counter = 0;
    char temp;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf(" %c", &board[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            swap(board[i][j], board[i+1][j]);

            for(int k = 1; k <= n; k++)
                for(int l = 1; l <= n; l++)
                {
                    counter = 1;
                    temp = board[k][l];
                    for(int x = l+1; x <= n; x++)
                    {
                        if(board[k][x] == temp && board[k][x] == board[k][x-1])
                            counter++;

                        else break;
                    }

                    ret = max(ret, counter);

                    counter = 1;
                    for(int y = k+1; y <= n; y++)
                    {
                        if(board[y][l] == temp && board[y][l] == board[y-1][l])
                            counter++;

                        else break;
                    }

                    ret = max(ret, counter);
                }

            swap(board[i][j], board[i+1][j]);

            swap(board[i][j], board[i][j+1]);

            for(int k = 1; k <= n; k++)
                for(int l = 1; l <= n; l++)
                {
                    counter = 1;
                    temp = board[k][l];
                    for(int x = l+1; x <= n; x++)
                    {
                        if(board[k][x] == temp && board[k][x] == board[k][x-1])
                            counter++;

                        else break;
                    }

                    ret = max(ret, counter);

                    counter = 1;
                    for(int y = k+1; y <= n; y++)
                    {
                        if(board[y][l] == temp && board[y][l] == board[y-1][l])
                            counter++;

                        else break;
                    }

                    ret = max(ret, counter);
                }

            swap(board[i][j], board[i][j+1]);
        }

    printf("%d", ret);

    return 0;
}
