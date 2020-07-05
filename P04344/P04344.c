#include <stdio.h>

int main()
{
    int n, i, j, number, score[1000];
    float avg, count;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        avg = 0, count = 0;

        scanf("%d", &number);

        for(j = 0; j < number; j++)
        {
            scanf("%d", &score[j]);
            avg += score[j];
        }
        avg = avg / number;

        for(j = 0; j < number; j++)
        {
            if(score[j] > avg)
                count += 1;
        }

        printf("%.3f%%\n", count / number * 100);
    }

    return 0;
}
