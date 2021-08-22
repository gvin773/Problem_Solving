#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

const ll MAX = LLONG_MAX;
ll n, q, p, k, c, ansi = MAX, ansp = MAX;

int main()
{
    onlycc;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> p >> k >> c;

        ll tp = p, num;
        if(q%k) num = q/k;
        else num = q/k-1;
        tp += c*num*(num+1)/2;

        if(tp < ansp)
        {
            ansi = i+1;
            ansp = tp;
        }
    }

    cout << ansi << ' ' << ansp;

    return 0;
}
