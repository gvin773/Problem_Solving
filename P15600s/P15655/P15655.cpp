#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, m, num[8];
vector<int> v;

void track(int now)
{
    if(v.size() == m)
    {
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    if(now >= n) return;

    v.push_back(num[now]);
    track(now+1);

    v.pop_back();
    track(now+1);
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num, num+n);
    track(0);

    return 0;
}
