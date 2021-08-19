#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll n;
bool p[1000001];
vector<ll> v, prime;
const int MAX = 1000000;

int main()
{
    onlycc;
    cin >> n;

    for(int i = 2; i <= MAX; i++)
    {
        if(!p[i]) prime.push_back(i);
        for(int j = i*2; j <= MAX; j+=i) p[j] = true;
    }

    for(auto i : prime)
    {
        while(n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }
    if(n > 1) v.push_back(n);

    if(v.size() <= 1) cout << -1;
    else
    {
        for(int i = 0; i < (int)v.size()-3; i += 2) cout << v[i]*v[i+1] << ' ';
        if(v.size() & 1) cout << v[v.size()-1]*v[v.size()-2]*v[v.size()-3];
        else cout << v[v.size()-1]*v[v.size()-2];
    }

    return 0;
}
