#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll k;
string p;
bool Prime[1000001];

int main()
{
    onlycc;
    cin >> p >> k;
    fill(Prime, Prime+1000001, 1);
    for(int i = 2; i <= 1000000; i++)
    {
        if(!Prime[i]) continue;
        for(int j = i*2; j <= 1000000; j+=i) Prime[j] = false;
    }

    for(int q = 2; q < k; q++)
    {
        if(!Prime[q]) continue;

        ll sum = 0;
        for(auto x : p) sum = (sum * 10 + x - '0') % q;
        if(sum == 0)
        {
            cout << "BAD" << ' ' << q;
            return 0;
        }
    }
    cout << "GOOD";

    return 0;
}
