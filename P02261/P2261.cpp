#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

pair<int, int> point[100000];

bool compare(const pair<int, int> &a, const pair<int ,int> &b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int dis(int p1, int p2)
{
    return (int)(pow(point[p1].first-point[p2].first, 2) + pow(point[p1].second-point[p2].second, 2));
}

int check(int start, int n)
{
    if(n == 2) return dis(start, start+1);
    if(n == 3) return min({dis(start, start+1), dis(start+1, start+2), dis(start+2, start)});

    int dl = check(start, n/2);
    int dr = check(start+n/2, n%2 == 0 ? n/2 : n/2+1);
    int dm = min(dl, dr);
    int line = (point[start+n/2].first + point[start+n/2-1].first)/2;

    vector<pair<int ,int>> arr;
    for(int i = start+n/2; i >= start; i--)
    {
        if(pow(line - point[i].first, 2) < dm)
            arr.push_back(point[i]);

        else break;
    }

    for(int i = start+n/2+1; i < start+n; i++)
    {
        if(pow(line - point[i].first, 2) < dm)
            arr.push_back(point[i]);

        else break;
    }

    sort(arr.begin(), arr.end(), compare);

    for(auto i = arr.begin(); i != arr.end(); i++)
    {
        for(auto j = i+1; j != arr.end(); j++)
        {
            if(pow(j->second-i->second, 2) >= dm) break;
            dm = min(dm, (int)(pow(j->second-i->second, 2) + pow(abs(i->first-j->first), 2)));
        }
    }

    return dm;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        point[i] = make_pair(x, y);
    }

    sort(point, point+n);

    printf("%d", check(0, n));

    return 0;
}
