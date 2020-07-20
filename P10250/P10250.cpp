#include <iostream>
using namespace std;

int main()
{
    int t, h, w, n;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d%d%d", &h, &w, &n);

        if(h == 1) printf("1%02d\n", n);
        else if(n%h != 0) printf("%d%02d\n", n%h, n/h+1);
        else if(n%h == 0) printf("%d%02d\n", h, n/h);
    }

    return 0;
}
