#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, t, g, ans;
bool visited[100000];
queue<int> q;

int bfs()
{
    q.push(n);
    visited[n] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            if(now == g) return level;
            q.pop();

            if(now+1 <= 99999 && !visited[now+1])
            {
                q.push(now+1);
                visited[now+1] = true;
            }

            int newn = 2*now;
            if(newn > 99999) continue;
            string num = to_string(newn);
            if(!(num[0] == '0' && num.size() == 1))
            {
                num[0] = num[0] - 1;
                if(num[0] == 0 && num.size() != 1) num = num.substr(1);
            }
            newn = stoi(num);
            if(!visited[newn])
            {
                q.push(newn);
                visited[newn] = true;
            }
        }
        level++;
        if(level > t)
        {
            cout << "ANG";
            exit(0);
        }
    }

    return 46464646;
}

int main()
{
    onlycc;
    cin >> n >> t >> g;
    if(n == g) cout << 0;
    else if((ans = bfs()) == 46464646) cout << "ANG";
    else cout << ans;

    return 0;
}
