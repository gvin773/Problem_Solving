#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

multiset<int> endtime;

int main()
{
    int n;
    pair<int, int> time[200000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int start, over;
        scanf("%d%d", &start, &over);
        time[i] =  make_pair(start, over);
    }

    sort(time, time+n);

    endtime.insert(-time[0].second);
    for(int i = 1; i < n; i++)
    {
        multiset<int>::iterator iter = endtime.lower_bound(-time[i].first);
        if(iter != endtime.end())
            endtime.erase(iter);

        endtime.insert(-time[i].second);
    }

    printf("%d", endtime.size());

    return 0;
}
