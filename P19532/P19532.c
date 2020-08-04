#include <stdio.h>

int main(void)
{
    int equation_1[3], equation_2[3], new_equ[3];
    int i;

    int x, y;
    int temp;

    /*input data*/
    for (i = 0; i < 3; i++)
        scanf("%d", &equation_1[i]);

    for (i = 0; i < 3; i++)
        scanf("%d", &equation_2[i]);


    if(equation_1[0] == 0)
    {
        y = equation_1[2]/equation_1[1];
        x = (equation_2[2]-equation_2[1]*y)/equation_2[0];
        printf("%d %d", x, y);
        return 0;
    }

    if(equation_1[1] == 0)
    {
        x = equation_1[2]/equation_1[0];
        y = (equation_2[2]-equation_2[0]*x)/equation_2[1];
        printf("%d %d", x, y);
        return 0;
    }

    if(equation_2[0] == 0)
    {
        y = equation_2[2]/equation_2[1];
        x = (equation_1[2]-equation_1[1]*y)/equation_1[0];
        printf("%d %d", x, y);
        return 0;
    }

    if(equation_2[1] == 0)
    {
        x = equation_2[2]/equation_2[0];
        y = (equation_1[2]-equation_1[0]*x)/equation_1[1];
        printf("%d %d", x, y);
        return 0;
    }

    temp = equation_1[0];

    for (i = 0; i < 3; i++)
        equation_1[i] *= equation_2[0];

    for (i = 0; i < 3; i++)
        equation_2[i] *= temp;

    for (i = 0; i < 3; i++)
        new_equ[i] = equation_1[i] - equation_2[i];


    y = new_equ[2] / new_equ[1];
    x = (equation_1[2] - y * equation_1[1]) / equation_1[0];

    printf("%d %d", x, y);

    return 0;
}
