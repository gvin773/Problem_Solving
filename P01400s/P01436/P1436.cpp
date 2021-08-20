#include <iostream>
using namespace std;

int n, i, counter, numcount;

int main()
{
    scanf("%d", &n);

    for(i = 666; ; i++)
    {
        int temp = i;
        numcount = 0;
        while(temp != 0)
        {
            if(temp%10 == 6 && temp/10%10 == 6 && temp/100%10 == 6)
            {
                numcount++;
                break;
            }

            temp /= 10;
        }

        if(numcount) counter++;

        if(counter == n) break;
    }

    printf("%d", i);

    return 0;
}
