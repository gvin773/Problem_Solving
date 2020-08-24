#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, len, tree[1000000];

int main()
{
    onlycc;
    cin >> n >> len;
    for(int i = 0; i < n; i++)
        cin >> tree[i];

    int M = 0, m = 1000000000;
    while(M+1 < m)
    {
        int mid = (M+m) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(tree[i] > mid)
                sum += tree[i] - mid;
        }

        if(sum >= len)
            M = mid;

        else
            m = mid;
    }

    cout << M;

    return 0;
}
