#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

char str[1001];

int main()
{
    fgets(str, 200, stdin);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if('a' <= str[i] && str[i] <= 'z')
        {
            for(int j = 0; j < 13; j++)
            {
                str[i]++;
                if(str[i] == 'z'+1)
                    str[i] = 'a';
            }
        }

        else if('A' <= str[i] && str[i] <= 'Z')
        {
            for(int j = 0; j < 13; j++)
            {
                str[i]++;
                if(str[i] == 'Z'+1)
                    str[i] = 'A';
            }
        }
    }

    printf("%s", str);

    return 0;
}
