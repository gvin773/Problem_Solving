#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, a[1000000];
vector<int> v;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    v.push_back(-9999999);
    for(int i = 0; i < n; i++)
    {
        if(v.back() < a[i])
        {
            v.push_back(a[i]);
        }

        else
        {
            auto iter = lower_bound(v.begin(), v.end(), a[i]);
            *iter = a[i];
        }
    }

    cout << v.size()-1;

    return 0;
}
