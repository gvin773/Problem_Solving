#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

/*
��Ʈ��ŷ�� ���ش�. ��, �̹� �����ϴ� ���ڸ� vector�� �ٽ� ���ְ� �Ͽ�
�ð�ȿ���� ���δ�.
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
