#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int a, p;
bool visited[100000000];
vector<ll> v;

ll get_next(ll now)
{
    ll ret = 0;
    while(now)
    {
        ret += pow(now%10, p);
        now /= 10;
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> a >> p;
    while(1)
    {
        if(visited[a]) break;
        visited[a] = true;
        v.push_back(a);
        a = get_next(a);
    }

    cout << find(v.begin(), v.end(), a) - v.begin();

    return 0;
}
