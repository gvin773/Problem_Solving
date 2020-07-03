#include <stdio.h>

void counter(int count[], int d);

int main()
{
    int a, b, c, d, count[10] = {0}, i;

    scanf("%d%d%d", &a, &b, &c);
    d = a * b * c;

    while(d / 10 != 0)
    {
        counter(count ,d);
        d = d / 10;

        if(d / 10 == 0) counter(count, d);
    }

    for(i = 0; i < 10; i++)
        printf("%d\n", count[i]);

    return 0;
}

void counter(int count[], int d)
{
    switch (d % 10) {
            case 0 : count[0]++; break;
            case 1 : count[1]++; break;
            case 2 : count[2]++; break;
            case 3 : count[3]++; break;
            case 4 : count[4]++; break;
            case 5 : count[5]++; break;
            case 6 : count[6]++; break;
            case 7 : count[7]++; break;
            case 8 : count[8]++; break;
            case 9 : count[9]++; break;
        }
}
