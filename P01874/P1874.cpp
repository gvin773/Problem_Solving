#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

int n, cnt = 1, x;
stack<int> s;
vector<int> num;
vector<char> v;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        num.push_back(x);
    }

    for(auto i = num.begin(); i != num.end(); i++)
    {
        if(!s.empty() && s.top() == *i && cnt > *i)
        {
            s.pop();
            v.push_back('-');
            continue;
        }

        else if(!s.empty() && s.top() != *i && cnt > *i)
        {
            cout << "NO";
            return 0;
        }

        int check = 0;
        for(; cnt <= *i; cnt++)
        {
            check = 1;
            s.push(cnt);
            v.push_back('+');
        }

        if(check)
        {
            s.pop();
            v.push_back('-');
        }
    }

    for(auto i = v.begin(); i != v.end(); i++)
        cout << *i << '\n';

    return 0;
}
