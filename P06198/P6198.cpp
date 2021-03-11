#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

/*
왼쪽에서 시작해서 monotone stack으로 내림차순을 만들어준다.
각 인덱스에서 스택의 사이즈는 앞선 인덱스의 빌딩 중 현위치보다 높은 빌딩의 개수이다.
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
