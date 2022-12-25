#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, k, len, fail[1001], virus[1001];
vector<int> v[222];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> len;
        v[i].resize(len);
        for(int j = 0; j < len; j++) cin >> v[i][j];
    }
    for(int i = 1; i < n; i++)
    {
        int SIZE = v[i].size();
        v[i].push_back(-1);
        for(int j = 0; j < SIZE; j++) v[i].push_back(v[i][SIZE-1-j]);
    }

    for(int start = 0; start+k-1 < v[0].size(); start++)
    {
        for(int i = 0; i < k; i++) virus[i] = v[0][start+i];
        memset(fail, 0, sizeof(fail));

        for(int i = 1, j = 0; i < k; i++)
        {
            while(j > 0 && virus[i] != virus[j]) j = fail[j-1];
            if(virus[i] == virus[j]) fail[i] = ++j;
        }

        for(int idx = 1; idx < n; idx++)
        {
            bool ok = false;
            for(int i = 0, j = 0; i < v[idx].size(); i++)
            {
                while(j > 0 && v[idx][i] != virus[j]) j = fail[j-1];
                if(v[idx][i] == virus[j])
                {
                    if(j == k-1)
                    {
                        ok = true;
                        break;
                    }
                    else j++;
                }
            }
            if(!ok) goto xy;
        }

        cout << "YES";
        return 0;
        xy:;
    }
    cout << "NO";

    return 0;
}
