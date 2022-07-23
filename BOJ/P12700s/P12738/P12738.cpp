#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[1000000];
vector<ll> v;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        if(v.empty()) v.push_back(a[i]);
        else if(v.back() < a[i]) v.push_back(a[i]);
        else
        {
            auto iter = lower_bound(v.begin(), v.end(), a[i]);
            *iter = a[i];
        }
    }
    cout << v.size();

    return 0;
}
