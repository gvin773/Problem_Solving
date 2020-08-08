#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll h[100001];

ll histogram(int s, int e)
{
    if(s == e) return h[s];
    if(s+1 == e) return max(max(h[s], h[e]), 2*(min(h[s], h[e])));

    int mid = (e+s)/2;
    ll ret = max(histogram(s, mid), histogram(mid+1, e)), minv = h[mid];
    int left = mid, right = mid, w = 1;

    while(right-left < e-s)
    {
        int le = (s < left) ? min(minv, h[left-1]) : -1;
        int re = (right < e) ? min(minv, h[right+1]) : -1;

        if(le <= re)
        {
            w++;
            right++;
            minv = re;
        }

        else
        {
            w++;
            left--;
            minv = le;
        }

        ret = max(ret, w*minv);
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", h+i);

    printf("%lld", histogram(1, n));

    return 0;
}
