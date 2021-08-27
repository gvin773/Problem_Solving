#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll t, n, a[100000], sorted[100000], ans;

void Merge(int left, int mid, int right)
{
    int i1 = left, i2 = mid+1, i3 = left;

    while(i1 <= mid && i2 <= right)
    {
        if(a[i1] <= a[i2]) sorted[i3++] = a[i1++];
        else
        {
            sorted[i3++] = a[i2++];
            ans += mid-i1+1;
        }
    }

    if(i1 > mid)
        for(int i = i2; i <= right; i++)
            sorted[i3++] = a[i];

    else
        for(int i = i1; i <= mid; i++)
            sorted[i3++] = a[i];

    for(int i = left; i <= right; i++)
        a[i] = sorted[i];
}

void merge_sort(int left, int right)
{
    if(left < right)
    {
        int mid = (left+right) / 2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        Merge(left, mid, right);
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        merge_sort(0, n-1);
        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
