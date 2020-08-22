#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

char str[1001];

int main()
{
    for(int i = 0; i < 100; i++)
    {
        if(!fgets(str, 200, stdin)) break;

        int cnt[4] = {0, 0, 0, 0}; //a, A, 1, ' '
        for(int i = 0; str[i] != '\0'; i++)
        {
            if('a' <= str[i] && str[i] <= 'z')
                cnt[0]++;

            else if('A' <= str[i] && str[i] <= 'Z')
                cnt[1]++;

            else if('0' <= str[i] && str[i] <= '9')
                cnt[2]++;

            else if(str[i] == ' ')
                cnt[3]++;
        }

        if(cnt[0]+cnt[1]+cnt[2]+cnt[3] != 0)
            printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
    }

    return 0;
}
