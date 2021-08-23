#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;
vector<int> v;

void track(int now)
{
    if(v.size() == m)
    {
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    if(now > n) return;

    v.push_back(now);
    track(now+1);

    v.pop_back();
    track(now+1);
}

int main()
{
    onlycc;
    cin >> n >> m;
    track(1);

    return 0;
}
