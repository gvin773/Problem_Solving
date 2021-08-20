#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

typedef long long ll;
ll box[3], n, counter[20], ret;
pair<ll, ll> cube[20];

void fillbox(ll l, ll w, ll h)
{
    if(l == 0 || w == 0 || h == 0) return;

    ll i, temp[3] = {l, w, h};
    sort(temp, temp+3);
    for(i = n-1; i >= 0; i--)
    {
        if(temp[0] >= cube[i].first)
        {
            counter[i] += (temp[0]/cube[i].first) * (temp[1]/cube[i].first) * (temp[2]/cube[i].first);
            break;
        }
    }

    fillbox(temp[0], temp[1], temp[2]%cube[i].first);

    fillbox(temp[0], temp[1]%cube[i].first, temp[2]-temp[2]%cube[i].first);

    fillbox(temp[0]%cube[i].first, temp[1]-temp[1]%cube[i].first, temp[2]-temp[2]%cube[i].first);
}

int main()
{
    scanf("%lld%lld%lld%lld", &box[0], &box[1], &box[2], &n);
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        cube[i] = make_pair((ll)pow(2,a), b);
    }

    sort(box, box+3);
    sort(cube, cube+n);

    fillbox(box[0], box[1], box[2]);

    for(int i = n-1; i >= 1; i--)
    {
        if(counter[i] > cube[i].second)
        {
            counter[i-1] += 8*(counter[i]-cube[i].second);
            counter[i] = cube[i].second;
        }
    }

    if(counter[0] > cube[0].second)
    {
        printf("-1");
        return 0;
    }

    for(int i = 0; i < n; i++)
        ret += counter[i];

    printf("%lld", ret);

    return 0;
}
