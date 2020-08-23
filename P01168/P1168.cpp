#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    vector<int> v;
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        v.push_back(i);

    cout << '<';
    int cur = 0, num = n;
    for(int i = 0; i < n; i++)
    {
        cur = (cur+k) % num;
        if(cur == 0) cur = num;
        if(i == n-1) cur = 0;

        if(i != n-1) cout << *(v.begin()+ (--cur)) << ", ";
        else cout << *v.begin() << '>';

        v.erase(v.begin() + cur);
        num--;
    }

    return 0;
}
