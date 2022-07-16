#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, r, m, k;
ld cost, d[111][111], d2[111][111], sum1, sum2;
string str, t, a, b;
map<string, int> city;
vector<ll> seq;

int main()
{
    onlycc;
    cin >> n >> r;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = d2[i][j] = 10000000000LL;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        city[str] = i;
        d[i][i] = 0;
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> str;
        seq.push_back(city[str]);
    }

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> t >> a >> b >> cost;
        d[city[a]][city[b]] = min(d[city[a]][city[b]], cost);
        if(t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") d2[city[a]][city[b]] = 0;
        else if(t == "S-Train" || t == "V-Train") d2[city[a]][city[b]] = min(d2[city[a]][city[b]], cost/2);
        else d2[city[a]][city[b]] = min(d2[city[a]][city[b]], cost);

        d[city[b]][city[a]] = min(d[city[b]][city[a]], cost);
        if(t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") d2[city[b]][city[a]] = 0;
        else if(t == "S-Train" || t == "V-Train") d2[city[b]][city[a]] = min(d2[city[b]][city[a]], cost/2);
        else d2[city[b]][city[a]] = min(d2[city[b]][city[a]], cost);
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }

    for(int i = 0; i < seq.size()-1; i++)
    {
        sum1 += d[seq[i]][seq[i+1]];
        sum2 += d2[seq[i]][seq[i+1]];
    }
    if(sum1 > sum2 + r) cout << "Yes";
    else cout << "No";

    return 0;
}
