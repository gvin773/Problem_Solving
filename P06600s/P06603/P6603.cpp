#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int k;

void track(int now, int cnt, vector<int> &v, int s[])
{
    if(now == k && cnt != 6) return;
    if(cnt == 6)
    {
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }

    v.push_back(s[now]);
    track(now+1, cnt+1, v, s);

    v.pop_back();
    track(now+1, cnt, v, s);
}

int main()
{
    onlycc;
    while(1)
    {
        cin >> k;
        if(k == 0) break;
        vector<int> v;
        int s[13] = {};
        for(int i = 0; i < k; i++) cin >> s[i];
        track(0, 0, v, s);
        cout << '\n';
    }

    return 0;
}
