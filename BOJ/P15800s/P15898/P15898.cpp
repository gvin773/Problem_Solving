#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int num[5][5];
    char color[5][5];
} material;

int board_num[6][6];
char board_color[6][6];
material mate[11];
int max_value = 0;
int temp_num1[6][6];
char temp_color1[6][6];
int temp_num2[6][6];
char temp_color2[6][6];
int move_num[6][6];
char move_color[6][6];

void move_mate(int i, int x, int y) //mate[i] (x,y)
{
    for(int a = 1; a <= 5; a++)
        for(int b = 1; b <= 5; b++)
        {
            move_num[a][b] = 0;
            move_color[a][b] = 'W';
        }

    if(x == 1 && y == 1)
    {
        for(int q = x; q <= x+3; q++)
            for(int w = y; w <= y+3; w++)
            {
                move_num[q][w] = mate[i].num[q][w];
                move_color[q][w] = mate[i].color[q][w];
            }
    }

    else if(x == 1 && y == 2)
    {
        for(int q = x; q <= x+3; q++)
            for(int w = y; w <= y+3; w++)
            {
                move_num[q][w] = mate[i].num[q][w-1];
                move_color[q][w] = mate[i].color[q][w-1];
            }
    }

    else if(x == 2 && y == 1)
    {
        for(int q = x; q <= x+3; q++)
            for(int w = y; w <= y+3; w++)
            {
                move_num[q][w] = mate[i].num[q-1][w];
                move_color[q][w] = mate[i].color[q-1][w];
            }
    }

    if(x == 2 && y == 2)
    {
        for(int q = x; q <= x+3; q++)
            for(int w = y; w <= y+3; w++)
            {
                move_num[q][w] = mate[i].num[q-1][w-1];
                move_color[q][w] = mate[i].color[q-1][w-1];
            }
    }
}

void rotation(int i) //rotate mate[i] .num && .color
{
    int tempi[5][5];
    char tempc[5][5];

    for(int x = 1; x <= 4; x++)
        for(int y = 1; y <= 4; y++)
        {
            tempi[x][y] = mate[i].num[5-y][x];
            tempc[x][y] = mate[i].color[5-y][x];
        }
    //rotation

    for(int x = 1; x <= 4; x++)
        for(int y = 1; y <= 4; y++)
        {
            mate[i].num[x][y] = tempi[x][y];
            mate[i].color[x][y] = tempc[x][y];
        }
    //change
}

void process(int a, int b, int c)
{
    if(a != b && b != c && c != a)
    {
        for(int ro1 = 1; ro1 <= 4; ro1++)
        {
            for(int ro2 = 1; ro2 <= 4; ro2++)
            {
                for(int ro3 = 1; ro3 <= 4; ro3++) //rotation
                {
                    for(int i = 1; i <= 2; i++)
                        for(int j = 1; j <= 2; j++) //cor
                        {
                            int temp = 0;
                            move_mate(a, i, j);
                            for(int x = 1; x <= 5; x++)
                                for(int y = 1; y <= 5; y++)
                                {
                                    board_num[x][y] += move_num[x][y];
                                    if(board_num[x][y] < 0) board_num[x][y] = 0;
                                    else if(board_num[x][y] > 9) board_num[x][y] = 9;

                                    if(move_color[x][y] != 'W')
                                        board_color[x][y] = move_color[x][y];
                                }
                            //apply a

                            for(int q = 1; q <= 5; q++)
                                for(int w = 1; w <= 5; w++)
                                {
                                    temp_num1[q][w] = board_num[q][w];
                                    temp_color1[q][w] = board_color[q][w];
                                }

                            for(int i2 = 1; i2 <=2; i2++)
                                for(int j2 = 1; j2 <= 2; j2++)
                                {
                                    move_mate(b, i2, j2);
                                    for(int x = 1; x <= 5; x++)
                                        for(int y = 1; y <= 5; y++)
                                        {
                                            board_num[x][y] += move_num[x][y];
                                            if(board_num[x][y] < 0) board_num[x][y] = 0;
                                            else if(board_num[x][y] > 9) board_num[x][y] = 9;

                                            if(move_color[x][y] != 'W')
                                                board_color[x][y] = move_color[x][y];
                                        }
                                    //apply b

                                    for(int q = 1; q <= 5; q++)
                                        for(int w = 1; w <= 5; w++)
                                        {
                                            temp_num2[q][w] = board_num[q][w];
                                            temp_color2[q][w] = board_color[q][w];
                                        }

                                    for(int i3 = 1; i3 <= 2; i3++)
                                        for(int j3 = 1; j3 <= 2; j3++)
                                        {
                                            move_mate(c, i3, j3);
                                            for(int x = 1; x <= 5; x++)
                                                for(int y = 1; y <= 5; y++)
                                                {
                                                    board_num[x][y] += move_num[x][y];
                                                    if(board_num[x][y] < 0) board_num[x][y] = 0;
                                                    else if(board_num[x][y] > 9) board_num[x][y] = 9;

                                                    if(move_color[x][y] != 'W')
                                                        board_color[x][y] = move_color[x][y];
                                                }
                                            //apply c

                                            for(int x = 1; x <= 5; x++)
                                                for(int y = 1; y <= 5; y++)
                                                {
                                                    if(board_color[x][y] == 'R')
                                                        temp += 7*board_num[x][y];

                                                    else if(board_color[x][y] == 'B')
                                                        temp += 5*board_num[x][y];

                                                    else if(board_color[x][y] == 'G')
                                                        temp += 3*board_num[x][y];

                                                    else if(board_color[x][y] == 'Y')
                                                        temp += 2*board_num[x][y];
                                                }
                                            //temp == bomb value

                                            max_value = max(max_value, temp);
                                            temp = 0;
                                            for(int x = 1; x <= 5; x++)
                                                for(int y = 1; y <= 5; y++)
                                                {
                                                    board_num[x][y] = temp_num2[x][y];
                                                    board_color[x][y] = temp_color2[x][y];
                                                }
                                        }

                                        for(int x = 1; x <= 5; x++)
                                            for(int y = 1; y <= 5; y++)
                                            {
                                            board_num[x][y] = temp_num1[x][y];
                                            board_color[x][y] = temp_color1[x][y];
                                            }
                                }


                            for(int x = 1; x <= 5; x++)
                                for(int y = 1; y <= 5; y++)
                                {
                                    board_num[x][y] = 0;
                                    board_color[x][y] = 'W';
                                }
                        }

                    rotation(c);
                }

                rotation(b);
            }

            rotation(a);
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &mate[i].num[1][1], &mate[i].num[1][2], &mate[i].num[1][3], &mate[i].num[1][4]);
        scanf("%d%d%d%d", &mate[i].num[2][1], &mate[i].num[2][2], &mate[i].num[2][3], &mate[i].num[2][4]);
        scanf("%d%d%d%d", &mate[i].num[3][1], &mate[i].num[3][2], &mate[i].num[3][3], &mate[i].num[3][4]);
        scanf("%d%d%d%d", &mate[i].num[4][1], &mate[i].num[4][2], &mate[i].num[4][3], &mate[i].num[4][4]);
        scanf(" %c %c %c %c", &mate[i].color[1][1], &mate[i].color[1][2], &mate[i].color[1][3], &mate[i].color[1][4]);
        scanf(" %c %c %c %c", &mate[i].color[2][1], &mate[i].color[2][2], &mate[i].color[2][3], &mate[i].color[2][4]);
        scanf(" %c %c %c %c", &mate[i].color[3][1], &mate[i].color[3][2], &mate[i].color[3][3], &mate[i].color[3][4]);
        scanf(" %c %c %c %c", &mate[i].color[4][1], &mate[i].color[4][2], &mate[i].color[4][3], &mate[i].color[4][4]);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            board_color[i][j] = 'W';
            move_color[i][j] = 'W';
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                process(i, j, k);

    printf("%d", max_value);

    return 0;
}
