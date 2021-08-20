#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll a[100001];

ll seq(int s, int e)
{
    if(s == e) return a[s]*a[s];
    if(s+1 == e) return max(max(a[s]*a[s], a[e]*a[e]), min(a[s],a[e])*(a[s]+a[e]));

    int mid = (e+s)/2;
    ll ret = max(seq(s, mid), seq(mid+1, e)), sum = a[mid], minv = a[mid];
    int left = mid, right = mid;

    while(right-left < e-s)
    {
        int le = (s < left) ? min(minv, a[left-1]) : -1;
        int re = (right < e) ? min(minv, a[right+1]) : -1;

        if(le*(sum+a[left-1]) <= re*(sum+a[right+1]))
        {
            right++;
            sum += a[right];
            minv = re;
        }

        else
        {
            left--;
            sum += a[left];
            minv = le;
        }

        ret = max(ret, sum*minv);
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", a+i);

    printf("%lld", seq(1, n));

    return 0;
}
