#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

string str;
stack<char> s;

int main()
{
    onlycc;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while(1)
            {
                if(s.empty() || s.top() == '(') break;
                else if((str[i] == '*'||str[i] == '/') && (s.top() == '+'||s.top() == '-')) break;
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }

        else if(str[i] == '(') s.push(str[i]);
        else if(str[i] == ')')
        {
            while(s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else cout << str[i];
    }

    while(s.size())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
