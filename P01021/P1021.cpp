#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;

int n, m, loc, ret;
deque<int> d;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        d.push_back(i);

    for(int i = 0; i < m; i++)
    {
        cin >> loc;
        auto iter = find(d.begin(), d.end(), loc);
        int cnt = 1;
        for(auto i = d.begin(); i != iter; i++)
            cnt++;

        if(cnt <= ceil(n/(double)2))
        {
            while(1)
            {
                if(d.front() == loc) break;
                d.push_back(d.front());
                d.pop_front();
                ret++;
            }
        }

        else
        {
            while(1)
            {
                if(d.front() == loc) break;
                d.push_front(d.back());
                d.pop_back();
                ret++;
            }
        }

        d.pop_front();
        n--;
    }

    cout << ret;

    return 0;
}
