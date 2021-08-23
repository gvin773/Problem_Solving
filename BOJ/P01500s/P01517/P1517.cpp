#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
버블 정렬의 swap 수는 병합 정렬의 swap 수와 같음
따라서 병합 정렬을 이용하고, 병합 과정에서 swap 수를 계산해주면 됨
swap 수는 R 배열의 값을 새 배열에 넣을때 L 배열에 남아 있는 수와 같음
(L 배열에 남은 것들을 방금 새 배열에 넣은 것보다 전부 오른쪽으로 이동시켜야 하므로)
*/

ll n, a[500000], sorted[500000], ans;

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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    merge_sort(0, n-1);
    cout << ans;

    return 0;
}
