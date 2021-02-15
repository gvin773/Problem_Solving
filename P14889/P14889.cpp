#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n, s[20][20], m = 46464646, ret;
vector<int> v;

void track(int now)
{
    if(v.size() == n/2)
    {
        int temp = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(find(v.begin(), v.end(), i) == v.end() && find(v.begin(), v.end(), j) == v.end())
                    temp += s[i][j];
        m = min(m, abs(temp-ret));
        return;
    }
    if(now == n) return;

    for(int i : v)
    {
        ret += s[i][now];
        ret += s[now][i];
    }
    v.push_back(now);
    track(now+1);

    v.pop_back();
    for(int i : v)
    {
        ret -= s[i][now];
        ret -= s[now][i];
    }
    track(now+1);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> s[i][j];
    track(0);
    cout << m;

    return 0;
}
