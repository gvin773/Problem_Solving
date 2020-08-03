#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    while(1)
    {
        int a, b, counter, i;
        scanf("%d%d", &a, &b);
        if(a == 0 && b == 0) break;

        if(a > b)
        {
            for(i = 1; b*i < a; i++)
                if(b*i == a) break;

            if(b*i > a) counter = 3;
            else counter = 2;
        }

        else
        {
            for(i = 1; a*i < b; i++)
                if(a*i == b) break;

            if(a*i > b) counter = 3;
            else counter = 1;
        }

        switch (counter)
        {
            case 1 : printf("factor\n"); break;
            case 2 : printf("multiple\n"); break;
            case 3 : printf("neither\n"); break;
        }
    }
    return 0;
}
