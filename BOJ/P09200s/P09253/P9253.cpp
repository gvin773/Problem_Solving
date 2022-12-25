#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll fail[100001];
string a[2], c;
bool flag[2];

int main()
{
    onlycc;
    cin >> a[0] >> a[1] >> c;
    for(int tc = 0; tc < 2; tc++)
    {
        memset(fail, 0, sizeof(fail));

        for(int i = 1, j = 0; i < c.size(); i++)
        {
            while(j > 0 && c[i] != c[j]) j = fail[j-1];
            if(c[i] == c[j]) fail[i] = ++j;
        }

        for(int i = 0, j = 0; i < a[tc].size(); i++)
        {
            while(j > 0 && a[tc][i] != c[j]) j = fail[j-1];
            if(a[tc][i] == c[j])
            {
                if(j == c.size()-1)
                {
                    flag[tc] = true;
                    j = fail[j];
                }
                else j++;
            }
        }
    }
    if(flag[0] && flag[1]) cout << "YES";
    else cout << "NO";

    return 0;
}
