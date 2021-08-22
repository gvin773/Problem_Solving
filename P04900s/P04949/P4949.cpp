#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int main()
{
    onlycc;
    while(1)
    {
        stack<char> s;
        string str;
        getline(cin, str);
        if(str == ".") break;

        int cnt = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '(') s.push(str[i]);
            else if(str[i] == '[') s.push(str[i]);

            else if(str[i] == ')')
            {
                if(!s.empty() && s.top() == 'c') s.pop();
                if(!s.empty() && s.top() == '(') s.pop();
                else
                {
                    cout << "no\n";
                    cnt = 1;
                    break;
                }
            }

            else if(str[i] == ']')
            {
                if(!s.empty() && s.top() == 'c') s.pop();
                if(!s.empty() && s.top() == '[') s.pop();
                else
                {
                    cout << "no\n";
                    cnt = 1;
                    break;
                }
            }

            else if(str[i] != ' ')
            {
                if(s.empty() || s.top() != 'c')
                    s.push('c');
            }
        }

        if(cnt == 0 && s.empty()) cout << "yes\n";
        else if(cnt == 0)
        {
            while(s.size())
            {
                if(s.top() != 'c')
                {
                    cout << "no\n";
                    break;
                }
                else s.pop();
            }

            if(s.empty()) cout << "yes\n";
        }
    }

    return 0;
}
