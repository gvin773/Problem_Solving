#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

int n, m, num[8];
vector<int> v;
set<vector<int>> s;

void track(int now)
{
    if(v.size() == m)
    {
        s.insert(v);
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
    for(auto i = s.begin(); i != s.end(); i++)
    {
        for(int j : *i)
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}
