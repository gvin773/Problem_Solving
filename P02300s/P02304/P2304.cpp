#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

pair<int, int> p[1000]; //L, H
int n, ret;
stack<pair<int, int>> s1, s2;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, h;
        cin >> l >> h;
        p[i] = make_pair(l, h);
    }

    sort(p, p+n);

    s1.push(p[0]);
    for(int i = 1; i < n; i++)
    {
        if(s1.top().second < p[i].second)
        {
            ret += (p[i].first-s1.top().first)*s1.top().second;
            s1.pop();
            s1.push(p[i]);
        }
    }

    s2.push(p[n-1]);
    for(int i = n-2; i >= 0; i--)
    {
        if(s2.top().second < p[i].second)
        {
            ret += (s2.top().first-p[i].first)*s2.top().second;
            s2.pop();
            s2.push(p[i]);
        }
    }

    cout << ret + (1+abs(s1.top().first-s2.top().first))*min(s1.top().second, s2.top().second);

    return 0;
}
