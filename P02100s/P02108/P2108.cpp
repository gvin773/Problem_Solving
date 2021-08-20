#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int num[500000], counter[10000], mode[10000];

int main()
{
    onlycc;
    int n, sum = 0, maxv = -5000, minv = 5000, temp = 0;
    cin >> n;

    for(int i = 0; i < 10000; i++)
        mode[i] = 464646;

    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
        counter[num[i]+4000]++;
    }

    sort(num, num+n);

    for(int i = 0; i < 10000; i++)
    {
        if(counter[i] != 0)
        {
            maxv = max(maxv, i-4000);
            minv = min(minv, i-4000);
            temp = max(temp, counter[i]);
        }
    }

    int j = 0;
    for(int i = 0; i < 10000; i++)
    {
        if(counter[i] == temp)
            mode[j++] = i-4000;
    }

    if(mode[1] != 464646) mode[0] = mode[1];

    cout << (int)floor(sum/(float)n+0.5) << endl
    << num[n/2] << endl << mode[0] << endl << maxv-minv;

    return 0;
}
