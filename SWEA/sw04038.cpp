#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int t;
string b, s;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> b >> s;
        vector<int> match, Fail(s.size(), 0);
        for(int i = 1, j = 0; i < s.size(); i++)
        {
            while(j > 0 && s[i]^s[j]) j = Fail[j-1];
            if(s[i] == s[j]) Fail[i] = ++j;
        }

        for(int i = 0, j = 0; i < b.size(); i++)
        {
            while(j > 0 && b[i]^s[j]) j = Fail[j-1];
            if(b[i] == s[j])
            {
                j++;
                if(j == s.size())
                {
                    match.push_back(i-(int)s.size()+1);
                    j = Fail[s.size()-1];
                }
            }
        }

        cout << '#' << tc << ' ' << match.size() << '\n';
    }

    return 0;
}
