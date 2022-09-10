#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 1111;
int tc, h, v, x, y, match, A[SIZE], B[SIZE], pi[2000][2000], cnt1, cnt2;
vector<int> Edge[SIZE];
bool visited[SIZE];
string w;
char puzzle[2000][2000];

bool dfs(int now)
{
    visited[now] = true;
    for(auto next : Edge[now])
    {
        if(B[next] == -1 || (!visited[B[next]] && dfs(B[next])))
        {
            A[now] = next;
            B[next] = now;
            return true;
        }
    }

    return false;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        memset(puzzle, 0, sizeof(puzzle));
        memset(pi, 0, sizeof(pi));
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < SIZE; i++) Edge[i].clear();
        cin >> h >> v;
        for(int i = 0; i < h; i++)
        {
            cin >> x >> y >> w;
            for(int j = 0; j < w.size(); j++)
            {
                puzzle[y][x+j] = w[j];
                pi[y][x+j] = cnt1;
            }
            cnt1++;
        }
        for(int i = 0; i < v; i++)
        {
            cin >> x >> y >> w;
            for(int j = 0; j < w.size(); j++)
            {
                if(puzzle[y+j][x] != w[j] && puzzle[y+j][x] != '\0') Edge[pi[y+j][x]].push_back(cnt2);
                puzzle[y+j][x] = w[j];
            }
            cnt2++;
        }

        match = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for(int i = 0; i < cnt1; i++)
        {
            if(A[i] == -1)
            {
                memset(visited, 0, sizeof(visited));
                if(dfs(i)) match++;
            }
        }

        cout << cnt1+cnt2-match << '\n';
    }

    return 0;
}
