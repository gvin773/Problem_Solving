#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> task[1000];
bool day[1001];

int main()
{
    int n, ret = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int d, w;
        scanf("%d%d", &d, &w);
        task[i] = make_pair(w, d);
    }

    sort(task, task+n);

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = task[i].second; j > 0; j--)
        {
            if(day[j] == false)
            {
                ret += task[i].first;
                day[j] = true;
                break;
            }
        }
    }

    printf("%d", ret);

    return 0;
}
