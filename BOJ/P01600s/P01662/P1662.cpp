#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

/*
괄호 사이의 길이를 구해주고, 앞의 수를 곱해준다.
'('를 기준으로 레벨을 나눠준다.
길이를 더해줄 때는 같은 레벨인 경우만 더해 괄호 안에 괄호가 여러개 있는 경우를 처리한다.
*/

string str;
stack<char> s;
int level[50], cnt;

int main()
{
    onlycc;
    cin >> str;
    for(char i : str)
    {
        if(i == '(') cnt++;
        if(i != ')') s.push(i);
        else
        {
            int l = level[cnt];
            level[cnt] = 0;
            while(s.top() != '(')
            {
                l++;
                s.pop();
            }
            s.pop();

            l *= (s.top() - '0');
            level[--cnt] += l;
            s.pop();
        }
    }

    cout << level[0] + s.size();

    return 0;
}
