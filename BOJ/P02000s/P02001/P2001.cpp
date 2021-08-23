#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int n, m, k, a, b, c;
bool visited[101][1<<14];
vector<int> index;
vector<pair<int, int>> br[101];
queue<pair<int, int>> q;

int num(int x)
{
    int ret = 0;
    for(int i = 0; i < k; i++) if((x>>i) & 1) ret++;
    return ret;
}

int bfs()
{
    q.push({1, 0});
    visited[1][0] = true;

    int ans = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int cur = q.front().first;
            int cgem = q.front().second;
            q.pop();

            if(cur == 1) ans = max(ans, num(cgem));

            for(auto next : br[cur])
            {
                int pos = next.first, gem = cgem, W = next.second;
                if(!visited[pos][gem] && num(gem) <= W)
                {
                    visited[pos][gem] = true;
                    q.push({pos, gem});
                }

                if(num(gem)+1 <= W)
                {
                    int x;
                    for(x = 0; x < k; x++) if(index[x] == cur) gem |= (1<<x);
                    if(!visited[pos][gem])
                    {
                        visited[pos][gem] = true;
                        q.push({pos, gem});
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    onlycc;
    cin >> n >> m >> k; index.resize(k);
    for(int i = 0; i < k; i++) cin >> index[i];
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        br[a].push_back({b, c});
        br[b].push_back({a, c});
    }
    br[1].push_back({1, 100});

    cout << bfs();

    return 0;
}
