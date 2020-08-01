#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int n, ret = 1;
    pair<int, int> time[100000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int start, over;
        scanf("%d%d", &start, &over);
        time[i] =  make_pair(over, start);
    }

    sort(time, time+n);

    int temp = 0;
    for(int i = 1; i < n; i++)
    {
        if(time[i].second >= time[temp].first)
        {
            ret++;
            temp = i;
        }
    }

    printf("%d", ret);

    return 0;
}
