#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;

int n, dp[100];
pair<int, int> rope[100];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> rope[i].first >> rope[i].second;

    sort(rope, rope+n);

    fill(dp, dp+n, 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(rope[j].second > rope[i].second)
                dp[j] = max(dp[j], 1+dp[i]);
        }
    }

    cout << n - *max_element(dp, dp+n);

    return 0;
}
