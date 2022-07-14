#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k, d[6], len[6], M[2];
vector<int> idx;

int main()
{
    onlycc;
    cin >> k;
    for(int i = 0; i < 6; i++)
    {
        cin >> d[i] >> len[i];
        M[i&1] = max(M[i&1], len[i]);
    }
    for(int i = 0; i < 6; i++)
    {
        if(len[i] == M[0] || len[i] == M[1]) idx.push_back(i);
    }
    if(idx[0] == 0 && idx[1] == 5) cout << k*(M[0]*M[1] - len[2]*len[3]);
    else cout << k*(M[0]*M[1] - len[(idx[1]+2)%6]*len[(idx[1]+3)%6]);

    return 0;
}
