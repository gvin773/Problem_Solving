#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int n, p, cnt;
stack<int> s[7];

int main()
{
    onlycc;
    cin >> n >> p;
    for(int i = 0; i < n; i++)
    {
        int line, fret;
        cin >> line >> fret;

        if(s[line].empty())
        {
            s[line].push(fret);
            cnt++;
            continue;
        }

        while(!s[line].empty() && s[line].top() > fret)
        {
            s[line].pop();
            cnt++;
        }

        if(s[line].empty() || s[line].top() != fret)
        {
            s[line].push(fret);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
