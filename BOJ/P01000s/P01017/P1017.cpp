#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, x, match, A[2020], B[2020], ban;
vector<int> a, b, Edge[2020], ans;
bool visited[2020], Prime[2001], two;

bool dfs(int now)
{
    visited[now] = true;
    for(auto next : Edge[now])
    {
        if(next == ban) continue;
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
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x&1) a.push_back(x);
        else
        {
            if(i == 0) two = true;
            b.push_back(x);
        }
    }
    if(n&1)
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < 2001; i++) Prime[i] = true;
    for(int i = 4; i <= 2000; i+=2) Prime[i] = false;
    for(int i = 3; i <= 2000; i+=2)
    {
        if(!Prime[i]) continue;
        for(int j = i*i; j <= 2000; j+=i*2) Prime[j] = false;
    }

    if(!two)
    {
        for(int i = 1; i < a.size(); i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                if(Prime[a[i]+b[j]])
                {
                    Edge[a[i]].push_back(b[j]);
                    Edge[b[j]].push_back(a[i]);
                }
            }
        }

        for(int j = 0; j < b.size(); j++)
        {
            if(!Prime[a[0]+b[j]]) continue;
            ban = b[j];
            match = 0;

            memset(A, -1, sizeof(A));
            memset(B, -1, sizeof(B));
            for(auto i : a)
            {
                if(A[i] == -1)
                {
                    memset(visited, 0, sizeof(visited));
                    if(dfs(i)) match++;
                }
            }
            if(match == (n-2)/2) ans.push_back(b[j]);
        }
    }
    else
    {
        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 1; j < b.size(); j++)
            {
                if(Prime[a[i]+b[j]])
                {
                    Edge[a[i]].push_back(b[j]);
                    Edge[b[j]].push_back(a[i]);
                }
            }
        }

        for(int j = 0; j < b.size(); j++)
        {
            if(!Prime[a[j]+b[0]]) continue;
            ban = a[j];
            match = 0;

            memset(A, -1, sizeof(A));
            memset(B, -1, sizeof(B));
            for(auto i : b)
            {
                if(A[i] == -1)
                {
                    memset(visited, 0, sizeof(visited));
                    if(dfs(i)) match++;
                }
            }
            if(match == (n-2)/2) ans.push_back(a[j]);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.empty()) cout << -1;
    else for(auto x : ans) cout << x << ' ';

    return 0;
}
