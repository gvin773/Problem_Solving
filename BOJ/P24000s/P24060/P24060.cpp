#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, k, A[500000], cnt;

void merge(ll p, ll q, ll r)
{
    int tmp[r+1];
    int i = p, j = q+1, t = 1;
    while(i <= q && j <= r)
    {
        if(A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while(i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];
    i = p, t = 1;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        if(++cnt == k)
        {
            cout << tmp[t-1];
            exit(0);
        }
    }
}

void merge_sort(ll p, ll r)
{
    if(p < r)
    {
        int q = (p+r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> A[i];
    merge_sort(0, n-1);
    cout << -1;

    return 0;
}
