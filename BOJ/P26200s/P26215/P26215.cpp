#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, s;
vector<ll> a;

int main()
{
    onlycc;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < 1440; i++)
    {
        if(a.size() == 1)
        {
            a[0]--;
            if(!a[0])
            {
                cout << i+1;
                return 0;
            }
        }
        else
        {
            a[a.size()-1]--;
            a[a.size()-2]--;
            sort(a.begin(), a.end());
            reverse(a.begin(), a.end());
            if(!a.back()) a.pop_back();
            if(!a.back()) a.pop_back();
            if(a.empty())
            {
                cout << i+1;
                return 0;
            }
            sort(a.begin(), a.end());
        }
    }
    cout << -1;

    return 0;
}
