#include <iostream>
using namespace std;

int num[21];
int n, s, counter;

void check(int current, int sum)
{
    if(current == n+1) return;

    if(sum+num[current] == s) counter++;

    check(current+1, sum);

    check(current+1, sum+num[current]);
}

int main()
{
    scanf("%d%d", &n, &s);

    for(int i = 1; i <= n; i++)
        scanf("%d", num+i);

    check(1, 0);

    printf("%d", counter);

    return 0;
}
