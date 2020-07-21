#include <cstdio>
#include <algorithm>
using namespace std;

int t[51]; //t_50 == 1275

int main()
{
    int T, n, cou1, cou2, tri;
    scanf("%d", &T);

    for(int i = 1; i <= 50; i++)
        t[i] = i*(i+1)/2;

    for(int i = 0; i < T; i++)
    {
        cou1 = 0, cou2 = 0, tri = 0;
        scanf("%d", &n);

        for(int j = 1; j <= 50; j++)
        {
            for(int k = 1; k <= 50; k++)
            {
                for(int l = 1; l <= 50; l++)
                {
                    if(t[j] + t[k] + t[l] == n)
                    {
                        cou1 = 0, cou2 = 0, tri = 1;
                        break;
                    }
                }

                if(cou1) break;
            }

            if(cou2) break;
        }

        printf("%d\n", tri);
    }

    return 0;
}
