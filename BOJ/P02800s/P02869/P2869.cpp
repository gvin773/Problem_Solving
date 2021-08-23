#include <iostream>
#include <cmath>

int main()
{
    int a, b, v;

    scanf("%d%d%d", &a, &b, &v);

    printf("%d", (int)ceil((v-b)/(double)(a-b)));

    return 0;
}
