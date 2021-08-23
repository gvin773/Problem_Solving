#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int k, num;
stack<int> s;
ll sum;

int main()
{
    onlycc;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> num;
        if(num == 0) s.pop();
        else s.push(num);
    }

    while(s.size())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}
