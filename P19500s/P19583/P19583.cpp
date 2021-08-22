#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

int cnt, s, e, q, ans;
string time[3], chat[100050], name[100050];
set<string> S;

int main()
{
    onlycc;
    for(int i = 0; i < 3; i++) cin >> time[i];
    while(1)
    {
        cin >> chat[cnt];
        if(cin.eof() == true) break;
        cin >> name[cnt++];
    }

    s = ((time[0][0]-'0')*10+(time[0][1]-'0'))*60+(time[0][3]-'0')*10+time[0][4]-'0';
    e = ((time[1][0]-'0')*10+(time[1][1]-'0'))*60+(time[1][3]-'0')*10+time[1][4]-'0';
    q = ((time[2][0]-'0')*10+(time[2][1]-'0'))*60+(time[2][3]-'0')*10+time[2][4]-'0';

    for(int i = 0; i < cnt; i++)
    {
        int t = ((chat[i][0]-'0')*10+(chat[i][1]-'0'))*60+(chat[i][3]-'0')*10+chat[i][4]-'0';
        if(t <= s) S.insert(name[i]);
        else if(e <= t && t <= q)
        {
            if(S.find(name[i]) != S.end())
            {
                ans++;
                S.erase(name[i]);
            }
        }
    }

    cout << ans;

    return 0;
}
