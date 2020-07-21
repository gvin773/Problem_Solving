#include <cstdio>
#include <algorithm>
using namespace std;

int arr[9], sor[7];
int sum, x, c;

int main()
{
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", arr+i);
        sum+= arr[i];
    }

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            if(i != j)
            {
                x = sum - arr[i] - arr[j];
                if(x == 100)
                {
                    for(int k = 0; k < 9; k++)
                    {
                        if(k != i && k != j)
                            sor[c++] = arr[k];
                    }
                }
            }
        }

    sort(sor, sor+7);

    for(int i = 0; i < 7; i++)
        printf("%d\n", *(sor+i));

    return 0;
}
