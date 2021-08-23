#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long ll;

/*
vector�� ���� ġŲ���� �����ϰ�, m���� ġŲ���� ���� ��� ����� ���� ���� ������ ġŲ �Ÿ��� ������ش�.
*/

int n, m, city[50][50], ans = 46464646;
vector<pair<int, int>> home, chicken;

void select(int cnt, vector<pair<int, int>> v)
{
    if(cnt == chicken.size() && v.size() != m) return;
    if(v.size() == m)
    {
        int sum = 0;
        for(auto h : home)
        {
            int s = 46464646;
            for(auto i : v)
            {
                s = min(s, abs(i.first-h.first) + abs(i.second-h.second));
            }
            sum += s;
        }
        ans = min(ans, sum);
        return;
    }

    select(cnt+1, v);

    v.push_back(chicken[cnt]);
    select(cnt+1, v);
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> city[i][j];
            if(city[i][j] == 1) home.push_back({i, j});
            else if(city[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<pair<int, int>> v;
    select(0, v);

    cout << ans;

    return 0;
}
