#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

/*
스택이 비었으면 담고, 아니면 스택의 맨 위 값과 현재 값을 비교하여 nge를 결정한다.
*주의* 수열에 같은 수가 존재할 수 있음.
*/

int n, a[1000000], nge[1000000];
stack<int> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(s.empty()) s.push(i);
        else
        {
            while(!s.empty() && a[i] > a[s.top()])
            {
                nge[s.top()] = a[i];
                s.pop();
            }
            if(s.empty() || a[i] <= a[s.top()]) s.push(i);
        }
    }

    while(!s.empty())
    {
        nge[s.top()] = -1;
        s.pop();
    }

    for(int i = 0; i < n; i++) cout << nge[i] << ' ';

    return 0;
}
