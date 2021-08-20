#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, m, ret;

    scanf("%d%d%d", &a, &b, &c);

    if(a == b && b == c) //abc
        ret = 10000 + a*1000;

    else if(a == b && b != c) //ab
        ret = 1000 + a*100;

    else if(c == b && b != a) //bc
        ret = 1000 + b*100;

    else if(a == c && b != c) //ca
        ret = 1000 + a*100;

    else
    {
        m = a;
        m = max(m, b);
        m = max(m, c);
        ret = m*100;
    }

    printf("%d", ret);

    return 0;
}
