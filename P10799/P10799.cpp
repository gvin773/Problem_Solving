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

    int temp = 0, ret = 0;
    char pre = '(';
    for(int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);

        if(s.top() == '(')
        {
            temp++;
        }

        else
        {
            if(pre == '(')
            {
            s.pop();
            s.pop();
            temp--;
            ret += temp;
            }

            else
            {
                temp--;
                s.pop();
                ret++;
            }
        }

        pre = str[i];
    }

    cout << ret;

    return 0;
}
