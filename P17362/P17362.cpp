#include <iostream>
using namespace std;

int main()
{
    int n;

    scanf("%d", &n);


    if(n % 4 == 3)
        printf("3");

    else if(n % 8 == 1)
        printf("1");

    else if(n % 8 == 5)
        printf("5");

    else if(n % 8 == 2 || n % 8 == 0)
        printf("2");

    else if(n % 8 == 4 || n % 8 == 6)
        printf("4");

    return 0;
}

