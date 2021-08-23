#include <iostream>
#include <algorithm>
using namespace std;

int a[50], n, num;

int main()
{
    scanf("%d", &num);

    for(int i = 0; i < num; i++)
        scanf("%d", a+i);

    sort(a, a+num);

    printf("%d", a[0]*a[num-1]);
    return 0;
}
