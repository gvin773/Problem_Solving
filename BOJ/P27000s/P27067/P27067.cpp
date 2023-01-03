#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[3333], b[3333], c[3333];
unordered_map<ll, ll> am, bm, cm;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        am[a[i]] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        bm[b[i]] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        cm[c[i]] = i;
    }
    for(int i = 0; i < n; i++)
    {
        ll L = -1, R = -1;
        for(int j = i+1; j < n; j++)
        {
            if(bm[a[j]] < bm[a[i]] && cm[a[j]] < cm[a[i]]) L = i, R = j;
        }

        if(L != -1 && R != -1)
        {
            for(int k = 0; k < L; k++) cout << a[k] << ' ';
            for(int k = L+1; k <= R; k++) cout << a[k] << ' ';
            cout << a[L] << ' ';
            for(int k = R+1; k < n; k++) cout << a[k] << ' ';
            return 0;
        }
    }

    return 0;
}
