#include <stdio.h>

int main()
{
    int x, y, day = 0;

    scanf("%d%d", &x ,&y);

    day = y;

    switch (x){
        case 12 : day += 30;
        case 11 : day += 31;
        case 10 : day += 30;
        case 9 : day += 31;
        case 8 : day += 31;
        case 7 : day += 30;
        case 6 : day += 31;
        case 5 : day += 30;
        case 4 : day += 31;
        case 3 : day += 28;
        case 2 : day += 31;
    }

    switch (day % 7){
        case 0 : printf("SUN"); break;
        case 1 : printf("MON"); break;
        case 2 : printf("TUE"); break;
        case 3 : printf("WED"); break;
        case 4 : printf("THU"); break;
        case 5 : printf("FRI"); break;
        case 6 : printf("SAT");
    }

    return 0;
}
