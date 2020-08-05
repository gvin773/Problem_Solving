#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        stack<int> s;
        char str[51];
        scanf("%s", str);
        int len = strlen(str), j;

        for(j = 0; j < len; j++)
        {
            if(str[j] == '(')
                s.push(1);

            else
            {
                if(s.size() == 0) break;
                s.pop();
            }
        }

        if(j != len)
        {
            printf("NO\n");
            continue;
        }

        if(s.size() == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
