#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int n, m, k, ans;
string L[50], temp[50];

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> L[i];
    cin >> k;

    for(int i = 0; i < n; i++)
    {
        int cnt = 0, on = 0;
        for(int j = 0; j < m; j++)
            if(L[i][j] == '0') cnt++;
        if(cnt > k) continue;
        if((k-cnt)%2 != 0) continue;

        for(int j = 0; j < n; j++) temp[j] = L[j];
        for(int j = 0; j < m; j++)
        {
            if(temp[i][j] == '0')
            {
                for(int k = 0; k < n; k++) temp[k][j] = '0' + (!(temp[k][j]%2));
            }
        }

        for(int j = 0; j < n; j++)
        {
            bool flag = true;
            for(int k = 0; k < m; k++)
            {
                if(temp[j][k] == '0')
                {
                    flag = false;
                    break;
                }
            }

            if(flag) on++;
        }

        ans = max(ans, on);
    }


    cout << ans;
    return 0;
}
