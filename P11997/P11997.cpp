#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

typedef long long ll;

int n, pSum[1002][1002], x[1001], y[1001], X, Y;
set<int> Xs, Ys;
unordered_map<int, int> xh, yh;

int Sum(int a, int b, int c, int d)
{
    return pSum[c][d] - pSum[a-1][d] - pSum[c][b-1] + pSum[a-1][b-1];
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        Xs.insert(x[i]);
        Ys.insert(y[i]);
    }

    for(int i : Xs) xh[i] = ++X;
    for(int i : Ys) yh[i] = ++Y;

    for(int i = 1; i <= n; i++)
        pSum[xh[x[i]]][yh[y[i]]]++;

    for(int i = 1; i <= X; i++)
    {
        for(int j = 1; j <= Y; j++)
        {
            pSum[i][j] += (pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1]);
        }
    }

    int ans = n;
    for(int i = 1; i <= X; i++)
    {
        for(int j = 1; j <= Y; j++)
        {
            int temp = max(Sum(1, 1, i, j), Sum(i+1, j+1, X, Y));
            temp = max(temp, Sum(1, j+1, i, Y));
            temp = max(temp, Sum(i+1, 1, X, j));

            ans = min(ans, temp);
        }
    }

    cout << ans;

    return 0;
}
