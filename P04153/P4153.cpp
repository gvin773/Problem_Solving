#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a[3];
    while(1)
    {
        scanf("%lld%lld%lld", a, a+1, a+2);
        if(*a == 0 && *a == *(a+1) && *a == *(a+2)) break;
        sort(a, a+3);
        if(a[0]*a[0]+a[1]*a[1] == a[2]*a[2] && a[0] != 0 && a[1] != 0 && a[2] != 0 && a[0] + a[1] > a[2]) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
