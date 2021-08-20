#include <iostream>
#include <algorithm>
using namespace std;

char str[11];

int main()
{
    scanf("%s", str);

    int i;
    for(i = 0; i < 11; i++)
    {
        if(str[i] == '\0')
            break;
    }

    sort(str, str+i);

    for(int j = i-1; j >= 0; j--)
        printf("%c", str[j]);

    return 0;
}
