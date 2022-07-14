#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n;
bool Prime[1100000];
unordered_set<ll> v;

int main()
{
    onlycc;
    cin >> n;
    fill(Prime, Prime+1100000, 1);
    for(ll i = 2; i < 1100000; i++)
    {
        if(Prime[i]) v.insert(i);
        else continue;

        for(ll j = i*i; j < 1100000; j+=i) Prime[j] = false;
    }
    for(int i = 3; i <= n; i+=2)
    {
        if(v.find(i) == v.end()) continue;

        ll temp, now = i;
        unordered_set<int> visited;
        while(1)
        {
            temp = now, now = 0;
            while(temp)
            {
                now += ((temp%10) * (temp%10));
                temp /= 10;
            }
            if(now == 1)
            {
                cout << i << '\n';
                break;
            }
            if(visited.find(now) != visited.end()) break;
            visited.insert(now);
        }
    }

    return 0;
}
