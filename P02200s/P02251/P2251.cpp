#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int a, b, c, wa, wb, wc;
vector<int> ans;
bool visited[201][201][201];

void dfs()
{
    visited[wa][wb][wc] = true;
    if(wa == 0) ans.push_back(wc);

    int ta = wa, tb = wb, tc = wc;
    if(wa > 0)
    {
        wa = wa < (b-wb) ? 0 : wa-(b-wb);
        wb = ta < (b-wb) ? wb+ta : b;
        if(!visited[wa][wb][wc]) dfs();
        wa = ta, wb = tb, wc = tc;

        wa = wa < (c-wc) ? 0 : wa-(c-wc);
        wc = ta < (c-wc) ? wc+ta : c;
        if(!visited[wa][wb][wc]) dfs();
        wa = ta, wb = tb, wc = tc;
    }

    if(wb > 0)
    {
        wb = wb < (a-wa) ? 0 : wb-(a-wa);
        wa = tb < (a-wa) ? wa+tb : a;
        if(!visited[wa][wb][wc]) dfs();
        wa = ta, wb = tb, wc = tc;

        wb = wb < (c-wc) ? 0 : wb-(c-wc);
        wc = tb < (c-wc) ? wc+tb : c;
        if(!visited[wa][wb][wc]) dfs();
        wa = ta, wb = tb, wc = tc;
    }

    if(wc > 0)
    {
        wc = wc < (a-wa) ? 0 : wc-(a-wa);
        wa = tc < (a-wa) ? wa+tc : a;
        if(!visited[wa][wb][wc]) dfs();
        wa = ta, wb = tb, wc = tc;

        wc = wc < (b-wb) ? 0 : wc-(b-wb);
        wb = tc < (b-wb) ? wb+tc : b;
        if(!visited[wa][wb][wc]) dfs();
        wa = ta, wb = tb, wc = tc;
    }
}

int main()
{
    onlycc;
    cin >> a >> b >> c; wc = c;
    dfs();
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i << ' ';

    return 0;
}
