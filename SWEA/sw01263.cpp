#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, n, arr[1000][1000];

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if(!arr[i][j]) arr[i][j] = 987654321;
                if(i == j) arr[i][j] = 0;
            }
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

        int ans = 987654321;
        for(int i = 0; i < n; i++)
        {
            int temp = 0;
            for(int j = 0; j < n; j++) if(i != j) temp += arr[i][j];
            ans = min(ans, temp);
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
