#include <stdio.h>

int main()
{
    int n, i, max;
    float *score;
    float sum = 0;

    scanf("%d", &n);
    score = malloc(sizeof(float) * n);

    for(i = 0; i < n; i++)
        scanf("%f", &score[i]);

    max = score[0];
    for(i = 0; i < n; i++)
    {
        if(max < score[i])
            max = score[i];
    }

    for(i = 0; i < n; i++)
        score[i] = (score[i] / max) * 100;

    for(i = 0; i < n; i++)
        sum += score[i];

    printf("%f", sum / n);

    return 0;
}
