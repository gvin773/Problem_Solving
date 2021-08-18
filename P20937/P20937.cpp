#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, c[500000], idx, cnt = 1;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c, c+n);
    while(idx != n)
    {
        int temp = 1;
        while(idx+1 != n && c[idx] == c[idx+1])
        {
            temp++;
            idx++;
        }
        cnt = max(cnt, temp);
        idx++;
    }

    cout << cnt;

    return 0;
}
