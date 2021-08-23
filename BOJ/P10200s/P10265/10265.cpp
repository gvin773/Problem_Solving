#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

typedef long long ll;

struct p
{
    int people;
    int cycle_num;
};

int n, k, MIN[1001], MAX[1001], cnt, dp[1010][1010];
bool visited[1001], finished[1001];
stack<int> s;
p ver[1001];

void dfs(int cur)
{
    if(visited[cur] == true && finished[cur] == false)
    {
        cnt++;
        ver[s.top()].cycle_num = cnt;
        MIN[cnt]++;
        s.pop();

        for(int now = ver[cur].people; now != cur; now = ver[now].people)
        {
            ver[s.top()].cycle_num = cnt;
            MIN[cnt]++;
            s.pop();
        }

        MAX[cnt] = MIN[cnt];
        while(1)
        {
            if(s.empty()) break;
            ver[s.top()].cycle_num = cnt;
            MAX[cnt]++;
            s.pop();
        }
        return;
    }

    else if(visited[cur] == true && finished[cur] == true)
    {
        while(!s.empty())
        {
            ver[s.top()].cycle_num = ver[cur].cycle_num;
            MAX[ver[cur].cycle_num]++;
            s.pop();
        }
        return;
    }

    s.push(cur);
    visited[cur] = true;

    dfs(ver[cur].people);

    finished[cur] = true;
}

int get_ans(int w, int cur)
{
    if(dp[w][cur] != -1) return dp[w][cur];

    dp[w][cur] = get_ans(w, cur-1);
    if(w >= MIN[cur])
    {
        for(int i = MIN[cur]; i <= MAX[cur] && i <= w; i++)
        {
            dp[w][cur] = max(dp[w][cur], get_ans(w-i, cur-1)+i);
        }
    }

    return dp[w][cur];
}

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> ver[i].people;

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
            dfs(i);
    }

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= cnt; i++) dp[0][i] = 0;
    for(int i = 0; i <= k; i++) dp[i][0] = 0;

    cout << get_ans(k, cnt);

    return 0;
}
