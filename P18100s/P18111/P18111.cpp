#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, b, arr[500][500], maxh = -1, H, t = 987654321;

int main()
{
    onlycc;
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            maxh = max(maxh, arr[i][j]);
        }

    for(int h = maxh; h >= 0; h--)
    {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(h >= arr[i][j]) sum1 += h - arr[i][j];
                else sum2 += arr[i][j] - h;
            }

        int temp = b + sum2;
        if(sum1 <= temp)
        {
            if(sum1 + 2*sum2 < t)
            {
                t = sum1 + 2*sum2;
                H = h;
            }

            else if(sum1 + 2*sum2 == t)
                H = max(H, h);
        }
    }

    cout << t << ' ' << H;

    return 0;
}
