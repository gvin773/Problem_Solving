#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll tc, m, x, mid;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        priority_queue<int, vector<int>, greater<int>> R;
        priority_queue<int> L;
        vector<int> v;

        cin >> m;
        for(int i = 1; i <= m; i++)
        {
            cin >> x;
            if(i&1)
            {
                if(i == 1) mid = x;
                else
                {
                    if(L.top() < x && x < R.top()) mid = x;
                    else if(x < L.top())
                    {
                        mid = L.top();
                        L.pop();
                        L.push(x);
                    }
                    else if(x > R.top())
                    {
                        mid = R.top();
                        R.pop();
                        R.push(x);
                    }
                }

                v.push_back(mid);
            }
            else
            {
                if(mid < x)
                {
                    L.push(mid);
                    R.push(x);
                }
                else
                {
                    L.push(x);
                    R.push(mid);
                }
            }
        }

        cout << v.size() << '\n';
        for(auto i : v) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
