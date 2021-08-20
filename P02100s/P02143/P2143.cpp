#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
각 배열에서 누적합 배열을 얻은 후, 각 누적합 배열을 더했을 때 t가 되는 케이스를 이분탐색을 이용하여 찾아준다.
합 배열에는 같은 값이 존재할 수 있으므로, 이분탐색으로는 lower, upper bound를 찾아준다.
*/

int n, m, a[1000], b[1000], cnt1, cnt2;
ll t, ans, s1[1000000], s2[1000000];

int main()
{
    onlycc;
    cin >> t >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i < n; i++)
    {
        s1[cnt1++] = a[i];
        for(int j = i+1; j < n; j++)
        {
            s1[cnt1] = a[j] + s1[cnt1-1];
            cnt1++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        s2[cnt2++] = b[i];
        for(int j = i+1; j < m; j++)
        {
            s2[cnt2] = b[j] + s2[cnt2-1];
            cnt2++;
        }
    }

    sort(s1, s1+cnt1);
    sort(s2, s2+cnt2);

    for(int i = 0; i < cnt1; i++)
    {
        int left = 0, right = cnt2-1;
        while(left+1 < right)
        {
            int mid = (left+right)/2;
            if(s1[i]+s2[mid] >= t) right = mid;
            else left = mid;
        }
        int L = left;

        right = cnt2-1;
        while(left+1 < right)
        {
            int mid = (left+right)/2;
            if(s1[i]+s2[mid] > t) right = mid;
            else left = mid;
        }
        int R = right;

        if(s1[i]+s2[L] == t && s1[i]+s2[R] == t) ans += (R-L+1);
        else if(s1[i]+s2[L] == t && s1[i]+s2[R] != t) ans += (R-L);
        else if(s1[i]+s2[L] != t && s1[i]+s2[R] == t) ans += (R-L);
        else ans += (R-L-1);
    }

    cout << ans;

    return 0;
}
