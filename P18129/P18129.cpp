#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int k, cnt = 1;
string s;
vector<pair<int, char>> v;
vector<int> ans;
bool visited[30];

int main()
{
    onlycc;
    cin >> s >> k;
    for(int i = 0; i < s.size(); i++)
        if('A' <= s[i] && s[i] <= 'Z') s[i] = (s[i]- 'A' + 'a');

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1])
        {
            cnt++;
        }
        else
        {
            v.push_back({cnt, s[i-1]});
            cnt = 1;
        }
    }
    v.push_back({cnt, s[s.size()-1]});

    for(int i = 0; i < v.size(); i++)
    {
        if(!visited[v[i].second-'a'])
        {
            visited[v[i].second-'a'] = true;
            if(v[i].first >= k) ans.push_back(1);
            else ans.push_back(0);
        }
    }

    for(auto i : ans) cout << i;

    return 0;
}
