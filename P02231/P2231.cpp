#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, sum = 0, temp, ret = 987654321;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        sum += i;
        temp = i;
        while(temp != 0)
        {
            sum += temp%10;
            temp /= 10;
        }

        if(sum == n)
            ret = min(ret, i);

        sum = 0;
    }

    if(ret != 987654321) printf("%d", ret);
    else printf("0");

    return 0;
}
