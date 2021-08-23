#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
먼저 오름차순으로 정렬을 해준다.
그리고 음수들은 절댓값이 큰 것들끼리 짝지어 곱해준다.
만약 음수의 개수가 홀수개인 경우, 마지막 남은 것을 0이 존재하지 않는 경우 더해준다.
양수들도 절댓값이 큰 것들끼리 짝지어 곱해준다.
만약 2개가 남았을때, 두개중 1이 있다면 모두 더해준다.
만약 양수의 개수가 홀수개인 경우, 마지막 남은 것을 더해준다.
*/

typedef long long ll;

int n, ans, cntm, cnt0, cntp;
vector<int> v;

int main()
{
    onlycc;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    for(int i : v)
    {
        if(i > 0) cntp++;
        else if(i < 0) cntm++;
        else cnt0++;
    }

    if(cntm%2 == 0)
    {
        for(int i = 0; i < cntm; i++)
        {
            ans += v[i]*v[i+1];
            i++;
        }
    }

    else
    {
        for(int i = 0; i < cntm-1; i++)
        {
            ans += v[i]*v[i+1];
            i++;
        }
        if(!cnt0) ans += v[cntm-1];
    }

    if(cntp%2 == 1) ans += v[cntm+cnt0];
    for(int i = n-1; i >= (cntp%2==1 ? cntm+cnt0+1 : cntm+cnt0); i--)
    {
        if(i != (cntp%2==1 ? cntm+cnt0+1 : cntm+cnt0) && v[i] != 1 && v[i-1] != 1)
        {
            ans += v[i]*v[i-1];
            i--;
        }
        else ans += v[i];
    }

    cout << ans;

    return 0;
}
