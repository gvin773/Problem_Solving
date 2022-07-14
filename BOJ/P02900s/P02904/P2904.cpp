#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, a, ans, score = 1;
bool Prime[1100000];
vector<ll> v;
unordered_map<ll, ll> m, num[110];

int main()
{
    onlycc;
    cin >> n;
    fill(Prime, Prime+1100000, 1);
    for(ll i = 2; i < 1100000; i++)
    {
        if(Prime[i]) v.push_back(i);
        else continue;

        for(ll j = i*i; j < 1100000; j+=i) Prime[j] = false;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a;

        for(int j = 0; j < v.size(); j++)
        {
            if(a == 1) break;
            while(a % v[j] == 0)
            {
                a /= v[j];
                if(m.find(v[j]) != m.end()) m[v[j]]++;
                else m[v[j]] = 1;
                if(num[i].find(v[j]) != num[i].end()) num[i][v[j]]++;
                else num[i][v[j]] = 1;
            }
        }
    }

    for(auto x : m)
    {
        ll number = x.second / n, now = x.first;
        if(number == 0) continue;
        for(int i = 0; i < n; i++)
        {
            if(num[i].find(now) == num[i].end()) num[i][now] = 0;
            if(num[i][now] < number) ans += (number - num[i][now]);
        }
        for(int i = 0; i < number; i++) score *= now;
    }
    cout << score << ' ' << ans;

    return 0;
}
