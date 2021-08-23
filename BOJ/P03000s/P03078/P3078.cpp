#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, k;
ll ret;
queue<int> q[21];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        while(q[str.size()].size())
        {
            if(i-q[str.size()].front() <= k)
            {
                ret += q[str.size()].size();
                break;
            }
            else q[str.size()].pop();
        }

        q[str.size()].push(i);
    }

    cout << ret;

    return 0;
}
