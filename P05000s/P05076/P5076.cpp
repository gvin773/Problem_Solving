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
        stack<string> s;
        string str;
        getline(cin, str);
        if(str.empty())
        {
            cout << "legal\n";
            continue;
        }
        if(str == "#") break;

        int cnt = 0;
        for(int i = 0 ; i < str.size(); i++)
        {
            if(str[i] == '<' && str[i+1] != '/')
            {
                string temp = str.substr(i, 1+str.find('>', i+1)-i);

                int a = temp.find(' ', 0);
                if(temp[a+1] == '/' && temp[a+2] == '>') continue;
                if(a != string::npos) temp = temp.substr(0, a) + ">";
                s.push(temp);
            }

            else if(str[i] == '<' && str[i+1] == '/')
            {
                if(str[i+2] == '>') continue;
                string temp = "<";
                temp += str.substr(i+2, 1+str.find('>', i+1)-(i+2));
                if(s.empty())
                {
                    cnt = 1;
                    break;
                }
                if(s.top() == temp) s.pop();
                else
                {
                    cnt = 1;
                    break;
                }
            }
        }

        if(cnt)
        {
            cout << "illegal\n";
            continue;
        }

        if(s.empty()) cout << "legal\n";
        else cout << "illegal\n";
    }

    return 0;
}
