#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, k[1000000], mf[5000001];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> k[i];
    for(int i = 2; i < 5000000; i++) mf[i] = i;
    mf[0] = mf[1] = -1;

    for(int i = 2; i*i <= 5000000; i++)
    {
        if(mf[i] != i) continue;
        for(int j = i*2; j <= 5000000; j += i) mf[j] = i;
    }

    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        while(k[i] != 1)
        {
            v.push_back(mf[k[i]]);
            k[i] /= mf[k[i]];
        }
        sort(v.begin(), v.end());
        for(int i : v) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
