#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

int n, p[48], s[48], t[48], cnt;
set<int> player[3];

bool same()
{
    for(int i = 0; i < n; i++)
        if(player[i%3].find(t[i]) == player[i%3].end()) return false;
    return true;
}

bool same_first()
{
    for(int i = 0; i < n; i++)
        if(t[i] != i) return false;
    return true;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        player[p[i]].insert(i);
    }
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) t[i] = i;

    while(!same())
    {
        int st[48] = {};
        for(int i = 0; i < n; i++) st[s[i]] = t[i];
        for(int i = 0; i < n; i++) t[i] = st[i];
        cnt++;

        if(same_first())
        {
            cout << -1;
            return 0;
        }
    }
    cout << cnt;

    return 0;
}
