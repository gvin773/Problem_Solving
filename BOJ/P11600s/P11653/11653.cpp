#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 2; n != 1;)
    {
        if(n%i == 0)
        {
            printf("%d\n", i);
            n /= i;
        }

        else i++;
    }

    return 0;
}
