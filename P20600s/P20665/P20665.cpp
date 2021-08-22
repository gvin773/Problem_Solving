#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, t, p, ans, where[501], sorted[101], gap[101];
string st, en;
pair<int, int> time[501];
bool seated[101], checked[501];

int main()
{
    onlycc;
    cin >> n >> t >> p;
    for(int i = 0; i < t; i++)
    {
        cin >> st >> en;
        time[i].first = 60*stoi(st.substr(0, 2)) + stoi(st.substr(2, 2)) - 540;
        time[i].second = 60*stoi(en.substr(0, 2)) + stoi(en.substr(2, 2)) - 540;
    }
    sort(time, time+t);

    for(int i = 0; i < 720; i++)
    {
        for(int j = 0; j < t; j++)
        {
            if(time[j].second == i && checked[j])
            {
                checked[j] = false;
                seated[where[j]] = false;
            }
        }

        for(int j = 0; j < t; j++)
        {
            if(time[j].first <= i && i < time[j].second && !checked[j])
            {
                int idx = 1, dis = 0;
                for(int k = 1; k <= n; k++)
                {
                    if(seated[k]) continue;

                    int temp = k, tdis = 987654321;
                    while(temp >= 1 && !seated[temp]) temp--;
                    if(temp != 0) tdis = k - temp;

                    temp = k;
                    while(temp <= n && !seated[temp]) temp++;
                    if(temp != n+1) tdis = min(tdis, temp-k);

                    if(tdis > dis)
                    {
                        idx = k;
                        dis = tdis;
                    }
                }

                seated[idx] = true;
                where[j] = idx;
                checked[j] = true;
            }
        }

        if(!seated[p]) ans++;
    }

    cout << ans;

    return 0;
}
