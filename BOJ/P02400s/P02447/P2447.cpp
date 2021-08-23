#include <iostream>
#include <string.h>
using namespace std;

char arr[3000][3000];

void star(int n, int x, int y)
{
    if(n == 3)
    {
        for(int i = x; i < x+3; i++)
        {
            for(int j = y; j < y+3; j++)
            {
                if(i == x+1 && j == y+1)
                    arr[j][i] = ' ';

                else
                    arr[j][i] = '*';
            }
        }
    }

    else
    {
            star(n/3, x, y); //box1
            star(n/3, n/3 + x, y); //box2
            star(n/3, n/3*2 + x, y); //box3
            star(n/3, x, n/3 + y); //box4

            for(int i = n/3 + 1; i <= n/3*2; i++) //box5
                for(int j = n/3 + 1; j <= n/3*2; j++)
                    arr[j][i] = ' ';

            star(n/3, n/3*2 + x, n/3 + y); //box6
            star(n/3, x, n/3*2 + y); //box7
            star(n/3, n/3 + x, n/3*2 + y); //box8
            star(n/3, n/3*2 + x, n/3*2 + y); //box9
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < 3000; i++)
        memset(arr[i], 32, sizeof(char)*3000);

    star(n, 1, 1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%c", arr[i][j]);

        puts("");
    }

    return 0;
}
