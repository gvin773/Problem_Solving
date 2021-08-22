#include <iostream>
#include <algorithm>
using namespace std;

int counting[10001];

int main()
{
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        counting[a]++;
    }

    for(int i = 1; i <= 10000; i++)
    {
        for(; counting[i] != 0; counting[i]--)
            printf("%d\n", i);
    }

    return 0;
}
