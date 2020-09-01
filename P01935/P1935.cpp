#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int n;
double v[1000], ans;
string str;
stack<int> s;

int main()
{
    onlycc;
    cin >> n >> str;
    for(int i = 'A'; i < 'A'+n; i++)
        cin >> v[i];

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            double b = v[s.top()];
            s.pop();
            double a = v[s.top()];
            s.pop();
            if(str[i] == '+')
            {
                s.push(n+1);
                v[n+1] = a+b;
            }
            else if(str[i] == '-')
            {
                s.push(n+1);
                v[n+1] = a-b;
            }
            else if(str[i] == '*')
            {
                s.push(n+1);
                v[n+1] = a*b;
            }
            else if(str[i] == '/')
            {
                s.push(n+1);
                v[n+1] = a/b;
            }
            n++;
        }

        else s.push(str[i]);
    }

    cout << fixed;
    cout.precision(2);
    cout << v[n];

    return 0;
}
