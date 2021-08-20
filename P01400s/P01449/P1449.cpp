#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, L, counter = 0, location[1001];
    bool water[1001];

    scanf("%d%d", &N, &L);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &location[i]);
        water[location[i]] = true;
    }

    sort(location+1, location+1+N);

    for(int i = 1; i <= N; i++)
    {
        if(water[location[i]] == true)
        {
            for(int j = 0; j < L; j++)
                water[location[i]+j] = false;

            counter++;
        }
    }

    printf("%d", counter);

    return 0;
}
