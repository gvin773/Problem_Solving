#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m, t[60], x[60][60], cnt;
unordered_set<int> s, s2;

int main()
{
    onlycc;
    cin >> n >> m >> t[0];
    for(int i = 0; i < t[0]; i++)
    {
        cin >> x[0][0];
        s.insert(x[0][0]);
    }

    for(int num = 0; num < n; num++)
    {
        for(int i = 0; i < m; i++)
        {
            if(!num) cin >> t[i];

            bool flag = true;
            for(int j = 0 ; j < t[i]; j++)
            {
                if(!num) cin >> x[i][j];
                if(flag && s.find(x[i][j]) != s.end()) flag = false;
            }
            if(!flag) for(int j = 0; j < t[i]; j++) s.insert(x[i][j]);
            if(num == n-1 && flag) cnt++;
        }
    }
    cout << cnt;

    return 0;
}

