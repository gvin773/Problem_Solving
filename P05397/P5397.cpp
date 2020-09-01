#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

typedef long long ll;

int t;

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        list<char> ans;
        cin >> str;

        auto now = ans.begin();
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '<')
            {
                if(now != ans.begin())
                    now--;
            }

            else if(str[i] == '>')
            {
                if(ans.size() == 0) continue;
                if(now != ans.end()) now++;
            }

            else if(str[i] == '-')
            {
                if(ans.size() != 0 && now != ans.begin())
                {
                    now--;
                    now = ans.erase(now);
                }
            }

            else
            {
                ans.insert(now, str[i]);
            }
        }

        for(auto iter = ans.begin(); iter != ans.end(); iter++)
            cout << *iter;

        cout << '\n';
    }

    return 0;
}
