#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, r1;
    int x2, y2, r2;
    int n, d, rsum, rsub;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
        rsum = (r1+r2)*(r1+r2), rsub = abs((r1-r2)*(r1-r2));
        d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

        if(!d)
        {
            if(r1 == r2) printf("-1\n");
            else printf("0\n");
        }

        else
        {
            if(d < rsub || d > rsum) printf("0\n");
            else if(d == rsub || d == rsum) printf("1\n");
            else if(rsub < d && d < rsum) printf("2\n");
        }
    }

    return 0;
}
