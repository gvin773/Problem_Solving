#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
    while(1)
    {
        char num[6];
        scanf("%s", num);
        int len = strlen(num);
        if(num[0] == '0' && len == 1) break;

        int i;
        for(i = 0; i < len/2; i++)
        {
            if(num[i] != num[len-i-1])
            {
                printf("no\n");
                break;
            }
        }

        if(i == len/2)
            printf("yes\n");
    }

    return 0;
}
