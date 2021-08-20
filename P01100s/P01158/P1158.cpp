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
    int cnt = 1;
    for(vector<int>::iterator iter = v.begin(); v.size() != 0;)
    {
        if(iter == v.end()) iter = v.begin();

        if(cnt == k)
        {
            cnt = 1;
            if(v.size() == 1) cout << *iter << '>';
            else cout << *iter << ", ";
            iter = v.erase(iter);
        }

        else
        {
            cnt++;
            iter++;
        }
    }

    return 0;
}
