#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int n, t[500000], ans[500000];
stack<pair<int, int>> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t[i];
    s.push({t[0], 1});
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && s.top().first < t[i]) s.pop();
        if(s.empty()) ans[i] = 0;
        else
        {
            ans[i] = s.top().second;
        }

        s.push({t[i], i+1});
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';

    return 0;
}
