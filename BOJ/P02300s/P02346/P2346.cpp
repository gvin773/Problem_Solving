#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;

typedef long long ll;

int n, temp;
list<pair<int ,int>> l; //first : ballon | second : next

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        l.push_back(make_pair(i, temp));
    }

    auto iter = l.begin();
    int next = 0;
    while(1)
    {
        if(next > 0)
        {
            next--;
            for(int i = 0; i < next; i++)
            {
                iter++;
                if(iter == l.end()) iter = l.begin();
            }
        }

        else
        {
            next++;
            for(int i = next; i < 0; i++)
            {
                if(iter == l.begin())
                {
                    iter = l.end();
                    iter--;
                }
                else iter--;
            }
        }

        next = iter->second;
        cout << iter->first << ' ';
        if(l.size() == 1) break;

        iter = l.erase(iter);

        if(iter == l.end() && next > 0) iter = l.begin();
        else if(iter == l.end() && next < 0)
        {
            iter = l.end();
            iter--;
        }
        else if(next < 0)
        {
            if(iter == l.begin())
            {
                iter = l.end();
                iter--;
            }
            else iter--;
        }
    }

    return 0;
}
