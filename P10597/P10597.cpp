#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

/*
백트래킹을 해준다. 단, 이미 존재하는 숫자를 vector에 다시 못넣게 하여
시간효율을 높인다.
*/

string per;
vector<int> v;
int checked[300];

void track(int now)
{
    if(now >= per.size())
    {
        for(int i = 1; i <= v.size(); i++) if(checked[i] != 1) return;

        for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        exit(0);
    }

    if(now+1 == (int)per.size() || (now+1 != (int)per.size() && per[now+1] != '0'))
    {
        int k = per[now] - '0';
        if(find(v.begin(), v.end(), k) == v.end())
        {
            v.push_back(k);
            checked[k]++;
            track(now+1);

            v.pop_back();
            checked[k]--;
        }
    }

    if(now != (int)per.size()-1)
    {
        int n = stoi(per.substr(now, 2));
        if(find(v.begin(), v.end(), n) == v.end())
        {
            v.push_back(n);
            checked[n]++;
            track(now+2);

            v.pop_back();
            checked[n]--;
        }
    }
}

int main()
{
    onlycc;
    cin >> per;
    track(0);

    return 0;
}
