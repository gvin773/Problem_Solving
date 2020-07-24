#include <iostream>
#include <algorithm>
using namespace std;

int person[51][3]; //[][1] == weight [][2] == height
int ret[51];
int n, counter;

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d%d", &person[i][1], &person[i][2]);

    for(int i = 1; i <= n; i++)
    {
        counter = 0;
        for(int j = 1; j <= n; j++)
            if(i != j && person[i][1] < person[j][1] && person[i][2] < person[j][2])
                counter++;

        ret[i] = counter + 1;
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", ret[i]);

    return 0;
}
