#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num[500000];
int counter[10000];
int mode[10000];

int main()
{
    int n, sum = 0, maxv = -5000, minv = 5000, temp = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", num+i);
        sum += num[i];
        counter[num[i]+4000]++;
    }

    sort(num, num+n);

    for(int i = 0; i < 10000; i++)
    {
        if(counter[i] != 0)
        {
            maxv = max(maxv, i-4000);
            minv = min(minv, i-4000);
            temp = max(temp, counter[i]);
        }
    }

    int j = 0;
    for(int i = 0; i < 10000; i++)
    {
        if(counter[i] == temp)
            mode[j++] = i-4000;
    }

    if(mode[1] != 0) mode[0] = mode[1];

    printf("%d\n%d\n%d\n%d", (int)floor(sum/(float)n+0.5), num[n/2], mode[0], maxv-minv);

    return 0;
}
