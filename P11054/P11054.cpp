#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a[1000], up[1000], down[1000];

int lisdown(int start)
{
    if(down[start] != -1) return down[start];

    int ret = 1;
    for(int i = start+1; i < n; i++)
    {
        if(a[start] > a[i])
            ret = max(ret, 1 + lisdown(i));
    }

    down[start] = ret;

    return ret;
}

int lisup(int rear)
{
    if(up[rear] != -1) return up[rear];

    int ret = 1;
    for(int i = rear-1; i >= 0; i--)
    {
        if(a[rear] > a[i])
            ret = max(ret, 1 + lisup(i));
    }

    up[rear] = ret;

    return ret;
}

int main()
{
    fill(up, up+1000, -1);
    fill(down, down+1000, -1);
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ret = 0;
    for(int i = 0; i < n; i++)
        ret = max(ret, lisup(i) + lisdown(i) - 1);

    cout << ret;

    return 0;
}
