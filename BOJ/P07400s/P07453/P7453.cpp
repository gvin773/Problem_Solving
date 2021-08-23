#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
�ΰ��� ���� ���� �����ְ�, ���� �յ��� �ٽ� ���ؼ� 0�� �Ǵ� ���̽��� �̺�Ž���� �̿��Ͽ� ã���ش�.
�� �迭���� ���� ���� ������ �� �����Ƿ�, �̺�Ž�����δ� lower, upper bound�� ã���ش�.
*/

int n, a[4000], b[4000], c[4000], d[4000], s1[16000000], s2[16000000], cnt;
ll ans;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            s1[cnt] = a[i] + b[j];
            s2[cnt++] = c[i] + d[j];
        }
    sort(s1, s1+cnt);
    sort(s2, s2+cnt);

    for(int i = 0; i < cnt; i++)
    {
        int left = 0, right = cnt-1;
        while(left+1 < right)
        {
            int mid = (left+right)/2;
            if(s1[i]+s2[mid] >= 0) right = mid;
            else left = mid;
        }
        int L = left;

        right = cnt-1;
        while(left+1 < right)
        {
            int mid = (left+right)/2;
            if(s1[i]+s2[mid] > 0) right = mid;
            else left = mid;
        }
        int R = right;

        if(s1[i]+s2[L] == 0 && s1[i]+s2[R] == 0) ans += (R-L+1);
        else if(s1[i]+s2[L] == 0 && s1[i]+s2[R] != 0) ans += (R-L);
        else if(s1[i]+s2[L] != 0 && s1[i]+s2[R] == 0) ans += (R-L);
        else ans += (R-L-1);
    }

    cout << ans;

    return 0;
}
