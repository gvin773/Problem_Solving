#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int n, cnt;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        stack<char> s;
        string str;
        cin >> str;

        for(int i = 0; i < str.size(); i++)
        {
            if(s.empty()) s.push(str[i]);

            else if(str[i] == s.top()) s.pop();
            else s.push(str[i]);
        }

        if(s.empty()) cnt++;
    }

    cout << cnt;

    return 0;
}
