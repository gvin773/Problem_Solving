#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

string str1, str2;
int t, dp[1001][1001];

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> str1 >> str2;
        int len1 = str1.size(), len2 = str2.size();
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        cout << '#' << tc << ' ' << dp[len1][len2] << '\n';
    }

    return 0;
}
