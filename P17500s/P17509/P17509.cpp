#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> data[12]; //first == D, second == V

int main()
{
    for(int i = 1; i <= 11; i++)
    {
        int D, V;
        scanf("%d%d", &D, &V);
        data[i] = make_pair(D, V);
    }

    sort(data+1, data+12);

    int sum[12] = {0, data[1].first, };
    for(int i = 2; i <= 11; i++)
        sum[i] += (sum[i-1] + data[i].first);

    int ret = 0;
    for(int i = 1; i <= 11; i++)
        ret += (sum[i] + 20*data[i].second);

    printf("%d", ret);

    return 0;
}
