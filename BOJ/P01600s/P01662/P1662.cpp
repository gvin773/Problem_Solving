#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

/*
��ȣ ������ ���̸� �����ְ�, ���� ���� �����ش�.
'('�� �������� ������ �����ش�.
���̸� ������ ���� ���� ������ ��츸 ���� ��ȣ �ȿ� ��ȣ�� ������ �ִ� ��츦 ó���Ѵ�.
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
