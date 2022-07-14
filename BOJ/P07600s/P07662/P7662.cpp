#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tc, k, n;
char c;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        multiset<int> s;
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> c >> n;
            if(c == 'I') s.insert(n);
            else
            {
                if(n == 1 && s.size())
                {
                    auto it = s.find(*s.rbegin());
                    s.erase(it);
                }
                else if(n == -1 && s.size())
                {
                    auto it = s.find(*s.begin());
                    s.erase(it);
                }
            }
        }
        if(s.size()) cout << *s.rbegin() << ' ' << *s.begin() << '\n';
        else cout << "EMPTY\n";
    }

    return 0;
}
