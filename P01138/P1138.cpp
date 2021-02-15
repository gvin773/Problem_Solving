#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, h[11];
vector<int> v;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];

    v.push_back(n);
    for(int i = n-1; i >= 1; i--)
        v.insert(v.begin()+h[i], i);

    for(int i : v) cout << i << ' ';

    return 0;
}
