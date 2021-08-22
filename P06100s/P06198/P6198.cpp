#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

/*
���ʿ��� �����ؼ� monotone stack���� ���������� ������ش�.
�� �ε������� ������ ������� �ռ� �ε����� ���� �� ����ġ���� ���� ������ �����̴�.
*/

ll n, h[80000], ans;
stack<int> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];

    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top() <= h[i]) s.pop();
        ans += s.size();
        s.push(h[i]);
    }

    cout << ans;

    return 0;
}
