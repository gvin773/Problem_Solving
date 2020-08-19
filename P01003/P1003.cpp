#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int fnum[41][2];

int main()
{
    onlycc;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < 41; j++)
            for(int k = 0; k < 2; k++)
                fnum[j][k] = 0;

        int n;
        cin >> n;

        fnum[0][0] = 1, fnum[1][1] = 1;
        for(int j = 2; j <= n; j++)
        {
            fnum[j][0] += fnum[j-1][0] + fnum[j-2][0];
            fnum[j][1] += fnum[j-1][1] + fnum[j-2][1];
        }

        cout << fnum[n][0] << ' ' << fnum[n][1] << '\n';
    }

    return 0;
}
