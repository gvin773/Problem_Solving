#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

/*
중복을 제거하고 정렬했을 때, 자신보다 작은 수의 개수(인덱스)가 결과이다.
unique로 중복제거 해주고 lower_bound로 인덱스를 찾아준다.
*/

int n;
vector<int> x, v;

int main()
{
    onlycc;
    cin >> n; x.resize(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    v = x;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i : x) cout << lower_bound(v.begin(), v.end(), i)-v.begin() << ' ';

    return 0;
}
