#define onlycc ios_base::sync_with_stdio(0); cin.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string str, word[100];
int n;
int dp[101];

bool check(int k)
{
    if(k == str.length()) return true;
    if(dp[k] != -1) return dp[k];

    dp[k] = 0;
    bool cnt = false;
    for(int i = 0; i < n; i++)
    {
        if(str.length() < k+word[i].length())
            continue;

        if(str.find(word[i], k) == k)
        {
            dp[k] = check(k+word[i].length());

            if(dp[k] == true)
            {
                cnt = true;
                break;
            }
        }

        if(cnt) break;
    }

    return dp[k];
}

int main()
{
    fill(dp, dp+101, -1);
    onlycc;
    cin >> str >> n;
    for(int i = 0; i < n; i++)
        cin >> word[i];

    cout << check(0);

    return 0;
}
