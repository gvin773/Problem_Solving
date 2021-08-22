#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

/*
�ߺ��� �����ϰ� �������� ��, �ڽź��� ���� ���� ����(�ε���)�� ����̴�.
unique�� �ߺ����� ���ְ� lower_bound�� �ε����� ã���ش�.
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
